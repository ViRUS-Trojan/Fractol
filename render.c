/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 19:30:27 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/21 18:48:22 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#define IS_LEFT(x) ((x)==0||(x)==2)
#define IS_TOP(x) ((x)==0||(x)==1)


/*
** render_quads ()
** Эта функция будет рисовать все пиксели фрактала для 1 квадранта
**	окно. Это позволяет многопоточность, так что с 4 потоками каждый может позаботиться о 1
** квадрантe.
*/

static void	*render_quads(void *args)
{
	int			x_ind;
	int			y_ind;
	int			x_end;
	int			y_end;
	t_envars	*env;

	env = ((t_targs *)args)->env;
	x_end = (IS_LEFT(((t_targs *)args)->quad)) ? env->w / 2 : env->w;
	y_end = (IS_TOP(((t_targs *)args)->quad)) ? env->h / 2 : env->h;
	x_ind = (IS_LEFT(((t_targs *)args)->quad)) ? -1 : env->w / 2 - 1;
	while (++x_ind < x_end)
	{
		y_ind = (IS_TOP(((t_targs *)args)->quad)) ? -1 : env->h / 2 - 1;
		while (++y_ind < y_end)
		{
			env->fract_func(env, idx(y_ind, x_ind, env->w));
		}
	}
	return (NULL);
}

/*
** render()
** Это сделает наш фрактал. Мы делаем это путем создания 4 потоков, которые будут
** работа над 4 квадрантами окна.
** Затем мы просто ждем окончания потоков и можем поместить полученную
** изображение в окно!
*/

/*
** Полезный фрагмент кода для определения времени:
**
**	#include <time.h>
**	#include <stdio.h>
** 	struct timespec start, finish;
**	double elapsed = 0;
**	clock_gettime(CLOCK_MONOTONIC, &start);
**
**	"Функция, о которой вы заботитесь и любите, чтобы время здесь шло"
**
**	clock_gettime(CLOCK_MONOTONIC, &finish);
**	elapsed = (finish.tv_sec - start.tv_sec);
**	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
**	ft_printf("time elapsed: %lf\n", elapsed);
*/

void		render(t_envars *env)
{
	int		i;
	t_targs	args[4];

	clear_img(env);
	i = -1;
	while (++i < 4)
	{
		args[i].env = env;
		args[i].quad = i;
		pthread_create(&env->tids[i], NULL, render_quads, (void *)&args[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(env->tids[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->image.image, 0, 0);
}