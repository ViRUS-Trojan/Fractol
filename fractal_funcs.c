/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:36:12 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/20 17:41:28 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Мандельброт ()
** Базовый набор Мандельброта, где 'c' определяется на основе местоположения пикселя
** в ограниченной области (см .: fractal_setup _ ?. c функции для получения границ)
*/

void    mandelbrod(void *environ, int pix_ind)
{
    t_fractal   f;
    t_envars    *env;

    env = (t_envars *)environ;
    f = env->f;
    f.x = pix_ind % env->w;
    f.y = pix_ind / env->w;
    if (env->psychedelic == 0)
    {
        f = calc_fract_min_max(env, f);
        env->f = f;
        f.c.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
		f.c.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
		f.z.r = 0;
		f.z.i = 0;
		env->iter_buf[pix_ind] = escape_time(env, f);
	}
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
    
}

/*
** Джулия()
** Набор Джулии * очень * похож на набор Мандельброта
** Единственное отличие состоит в том, что значение c определяется положением
** курсор мыши. Это буквально единственная разница ...
*/

void    julia(t_envars *env, int pix_ind)
{

}