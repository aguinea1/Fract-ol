/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:13:13 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 00:54:18 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	put_color_to_pixel(t_fract *fractal, int color)
{
	int	*buffer;

	buffer = fractal->pixel;
	buffer[((int)fractal->y * fractal->size_line / 4)
		+ (int)fractal->x] = color;
}

int	draw_fractal(t_fract *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < WIDTH)
	{
		while (fractal->y < HEIGHT)
		{
			if (ft_strncmp (fractal->fractol, "mandelbrot", 10) == 0)
				mandelbrot(fractal);
			else if (ft_strncmp (fractal->fractol, "julia", 5) == 0)
				julia(fractal, fractal->parameters.x, fractal->parameters.y);
			else
				burning_ships(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->init_mini, fractal->init_window,
		fractal->img, 0, 0);
	return (0);
}
