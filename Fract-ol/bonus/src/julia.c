/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:31:23 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/07 23:47:39 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_fract *fract, double cx, double cy)
{
	int		i;
	double	tmp;
	int		color;

	i = 0;
	fract->zx = ((fract->x - WIDTH / 2) / fract->zoom) + fract->off_x;
	fract->zy = ((fract->y - HEIGHT / 2) / fract->zoom) + fract->off_y;
	while (++i < fract->iter)
	{
		tmp = fract->zx;
		fract->zx = fract->zx * fract->zx - fract->zy * fract->zy + cx;
		fract->zy = 2 * fract->zy * tmp + cy;
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->iter)
		color = 0x000000;
	else
		color = simple_color(i, fract->iter);
	put_color_to_pixel(fract, color * (i % 255));
}

/*
 *	if (i == fract->iter) gradient color based on the iteration
		color = 0x000000;
	else
		color = simple_color(i, fract->iter);
	put_color_to_pixel(fract, color * (i % 255));
*/
