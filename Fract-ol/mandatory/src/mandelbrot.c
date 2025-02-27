/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:30:29 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 01:09:52 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_fract *fract)
{
	int		i;
	double	temp;
	double	cx;
	double	cy;
	int		color;

	i = 0;
	fract->zx = 0.0;
	fract->zy = 0.0;
	cx = ((fract->x - WIDTH / 2) / fract->zoom) + fract->off_x;
	cy = ((fract->y - HEIGHT / 2) / fract->zoom) + fract->off_y;
	while (++i < fract->iter)
	{
		temp = fract->zx * fract->zx - fract->zy * fract->zy + cx;
		fract->zy = 2 * fract->zx * fract->zy + cy;
		fract->zx = temp;
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->iter)
		color = 0x000000;
	else
		color = simple_color(i, fract->iter);
	put_color_to_pixel(fract, color);
}
