/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ships.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:53:59 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/07 23:59:34 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static double	my_fabs(double x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	burning_ships(t_fract *fract)
{
	int		i;
	double	tmp;
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
		tmp = fract->zx * fract->zx - fract->zy * fract->zy + cx;
		fract->zy = my_fabs(2.0 * fract->zx * fract->zy) + cy;
		fract->zx = my_fabs(tmp);
		if (fract->zx * fract->zx + fract->zy * fract->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fract->iter)
		color = 0x000000;
	else
		color = simple_color(i, fract->iter);
	put_color_to_pixel(fract, color);
}
