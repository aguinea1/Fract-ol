/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:58:49 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 08:58:40 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse(int button, int x, int y, t_fract *fract)
{
	double	zoom_iter;
	double	scroll_x;
	double	scroll_y;

	zoom_iter = 1.42;
	scroll_x = (x - 800 / 2) / fract->zoom + fract->off_x;
	scroll_y = (y - 800 / 2) / fract->zoom + fract->off_y;
	if (button == 5)
		zoom_iter = 1.10;
	else if (button == 4)
		zoom_iter = 0.90;
	else
		return (0);
	fract->zoom *= zoom_iter;
	fract->off_x = scroll_x - (x - WIDTH / 2) / fract->zoom;
	fract->off_y = scroll_y - (y - HEIGHT / 2) / fract->zoom;
	draw_fractal(fract);
	return (0);
}

static void	iterations(int but, t_fract *fractal)
{
	if (but == 109)
	{
		if (fractal->iter < 4200)
			fractal->iter += 20;
	}
	else
		if (fractal->iter > 20)
			fractal->iter -= 20;
}

int	keyboard(int button, t_fract *fract)
{
	if (button == 65307)
		close_window(fract);
	else if (button == 65361)
		fract->off_x -= 42 / fract->zoom;
	else if (button == 65363)
		fract->off_x += 42 / fract->zoom;
	else if (button == 65362)
		fract->off_y -= 42 / fract->zoom;
	else if (button == 65364)
		fract->off_y += 42 / fract->zoom;
	else if (button == 109 || button == 108)
		iterations(button, fract);
	else
		return (0);
	draw_fractal(fract);
	return (0);
}

/*int	mouse(int button, int x, int y, t_fract *fract)
{
	double	zoom_iter;
	double	scroll_x;
	double	scroll_y;

	zoom_iter = 1.42;
	scroll_x = (x - 800 / 2) / fract->zoom + fract->off_x;
	scroll_y = (y - 800 / 2) / fract->zoom + fract->off_y;
	if (button == 5) //scroll up
		zoom_iter = 1.10;
	else if (button == 4) //scroll down
		zoom_iter = 0.90;
	else
		return (0);
	fract->zoom *= zoom_iter;
	fract->off_x = scroll_x - (x - WIDTH / 2) / fract->zoom;
	fract->off_y = scroll_y - (y - HEIGHT / 2) / fract->zoom;
	draw_fractal(fract);
	return (0);
}*/
/*int	keyboard(int button, t_fract *fract)
{
	if (button == 65307) //ESC button
		close_window(fract);
	else if (button == 65361) //Left Arrow
		fract->off_x -= 42 / fract->zoom;
	else if (button == 65363) //Right arrow
		fract->off_x += 42 /fract->zoom;
	else if (button == 65362) // Up arrow
		fract->off_y -= 42 / fract->zoom;
	else if (button == 65364) //Down Arrow
		fract->off_y += 42 / fract->zoom;
	else if (button == 109 || button == 108 ) //M or L
			iterations(button, fract);
	else 
		return (0);
	draw_fractal(fract);
	return (0);
}*/
