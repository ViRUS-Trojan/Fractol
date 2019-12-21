/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_setup_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:42:59 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/21 19:46:49 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** setup_fract ()
** Инициализирует коэффициент масштабирования, координаты центра 'x, y' нашего фрактала как
** а также ширина наших размеров х и у.
*/

void	setup_julia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = 0.0;
	env->f.x_wid = 4.0;
	env->f.y_wid = 4.0;
}

void	setup_mandelbrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = -0.5;
	env->f.y_cent = 0.0;
	env->f.x_wid = 3.5;
	env->f.y_wid = 2.5;
}

void	setup_bship(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = -0.5;
	env->f.y_cent = -0.25;
	env->f.x_wid = 3.0;
	env->f.y_wid = 3.0;
}