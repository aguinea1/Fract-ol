/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:57:20 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 08:56:13 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	exit_msg(int error, t_fract *fract)
{
	if (error == 0)
	{
		ft_printf("%s\n", ERROR_BONUS);
		exit (1);
	}
	free (fract);
	exit (1);
}

static int	is_number(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (str[i] == '.' && dot == 0)
		{
			i++;
			dot++;
		}
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_julia_par(char **av, t_fract *fract)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	if (!av[2] || !av[3])
		exit_msg(0, fract);
	if (!is_number(av[2]) || !is_number(av[3]))
		exit_msg(0, fract);
	x = atodbl(av[2]);
	y = atodbl(av[3]);
	if (x < -2 || x > 2 || y < -2 || y > 2)
		exit_msg(0, fract);
	fract->parameters.y = x;
	fract->parameters.x = y;
}

static t_fract	*my_malloc(t_fract *fract)
{
	return (fract = malloc(sizeof(t_fract)), fract);
}

int	main(int ac, char **av)
{
	t_fract	*fract;

	fract = NULL;
	fract = my_malloc(fract);
	if (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0))
	{
		ft_julia_par(av, fract);
		fract->fractol = "julia";
	}
	else if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0))
		fract->fractol = "mandelbrot";
	else if (ac == 3 && (ft_strncmp(av[1], "burning", 7) == 0))
	{
		if (ft_strncmp(av[2], "ships", 5) == 0)
			fract->fractol = "burning ships";
		else
			exit_msg(0, fract);
	}
	else
		exit_msg(0, fract);
	minilibx_init(fract);
	draw_fractal(fract);
	mlx_loop(fract->init_mini);
	return (0);
}
