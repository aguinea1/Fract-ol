/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguinea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:01:39 by aguinea           #+#    #+#             */
/*   Updated: 2025/02/07 23:56:49 by aguinea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	simple_color(int i, int max_iter)
{
	int	r;
	int	g;
	int	b;
	int	color_value;

	color_value = (int)((double)i / max_iter * 255);
	r = (color_value * 2) % 256;
	g = (color_value * 5) % 256;
	b = (color_value * 10) % 256;
	return ((r << 16) | (g << 8) | b);
}
/*
 *
int simple_color(int i, int max_iter)
{
	int r;
	int g;
	int b;

    //iter num between 0 and 255
	int color_value = (int)((double)i / max_iter * 255);

    r = (color_value * 2) % 256;  // Red increases fast
    g = (color_value * 5) % 256;  // Green increases a bit slower
    b = (color_value * 10) % 256; // blue increses even slower

	//return the value in bits
    return (r << 16) | (g << 8) | b;
}*/
