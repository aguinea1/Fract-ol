/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:03 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 12:29:16 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define ERROR_FORMAT "Please enter \n\t\"./fractol mandelbrot\" \
		or \n\t\"./fractol julia <value_1> <value_2> (value beetwen 2 & -2)"
# define ERROR_BONUS "Please enter \n\t\"./fractol mandelbrot\" \
		or \n\t\"./fractol julia <value_1> <value_2> (values between -2 & 2)\" \
		or \n\t\"./fractol burning_ships\""

# include "../libft/libft.h"
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "../../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

typedef struct s_julia
{
	double	x;
	double	y;
}	t_julia;

typedef struct s_fract
{
	char	*fractol;
	void	*init_mini;
	void	*init_window;
	double	zoom;
	double	zx;
	double	zy;
	double	x;
	double	y;
	double	off_x;
	double	off_y;
	t_julia	parameters;
	void	*img;
	void	*pixel;
	int		bits;
	int		size_line;
	int		endian;
	int		iter;
	int		color;
}	t_fract;

int		main(int ac, char **av);

//UTILS
double	atodbl(char *s);
void	exit_msg(int error, t_fract *fract);

//MINILIB INIT
void	minilibx_init(t_fract	*fract);
int		close_window(t_fract *fract);

//FRACTAL DRAWING
int		draw_fractal(t_fract *fractal);
void	put_color_to_pixel(t_fract *fractal, int color);
void	mandelbrot(t_fract *fract);
void	julia(t_fract *fract, double cx, double cy);
int		simple_color(int i, int max_iter);
void	burning_ships(t_fract *fract);

//KEY PRESSING
int		keyboard(int button, t_fract *fract);
int		mouse(int button, int x, int y, t_fract *fract);
#endif
