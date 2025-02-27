/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilibx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:40:44 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/08 08:58:18 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	close_window(t_fract *fract)
{
	mlx_destroy_image(fract->init_mini, fract->img);
	mlx_destroy_window(fract->init_mini, fract->init_window);
	free (fract->init_mini);
	free(fract);
	exit (1);
	return (0);
}

static void	hook(t_fract *fract)
{
	mlx_key_hook(fract->init_window, keyboard, fract);
	mlx_mouse_hook(fract->init_window, mouse, fract);
	mlx_hook(fract->init_window, DestroyNotify,
		StructureNotifyMask, close_window, fract);
}

static void	fract_data(t_fract *fract)
{
	fract->zoom = 100;
	fract->iter = 40;
	fract->off_x = -1.21;
	fract->off_y = -1.21;
}

void	minilibx_init(t_fract	*fract)
{
	fract_data(fract);
	fract->init_mini = mlx_init();
	if (fract->init_mini == NULL)
		exit_msg(1, fract);
	fract->init_window = mlx_new_window(fract->init_mini, HEIGHT, WIDTH,
			"fractol");
	if (fract->init_window == NULL)
	{
		mlx_destroy_display(fract->init_mini);
		free(fract->init_mini);
		exit_msg(1, fract);
	}
	fract->img = mlx_new_image(fract->init_mini, WIDTH, HEIGHT);
	if (fract->img == NULL)
	{
		mlx_destroy_window(fract->init_mini, fract->init_window);
		mlx_destroy_display(fract->init_mini);
		free(fract->init_mini);
		exit_msg(1, fract);
	}
	fract->pixel = mlx_get_data_addr(fract->img, &fract->bits,
			&fract->size_line, &fract->endian);
	hook(fract);
}
/*
 *static void	hook(t_fract *fract)
 *	{
 *	mlx_key_hook(fract->init_window, keyboard, fract);
 *	//KeyPress & KeyPressMask are events that indicates to minilibx that a key 
 *	//has been pressed
 *	mlx_mouse_hook(fract->init_window, mouse,fract);
 *	mlx_hook(fract->init_window, DestroyNotify, 
 *			StructureNotifyMask, close_window, fract);
 *	//DestroyNotify is an event that detects when the window is closed
 *	//StructureNotifyMask: this event detects changes on the window structure
} */
