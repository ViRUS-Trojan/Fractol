/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 18:02:01 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/21 18:03:10 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "fractol.h"

static void	cleanup_env(t_envars *env)
{
	free(env->iter_buf);
	mlx_destroy_image(env->mlx, (&env->image)->image);
	mlx_destroy_window(env->mlx, env->win);
}

void		reset_env(t_envars *env)
{
	cleanup_env(env);
	setup_env(env);
}

/*
** keydown_hook - аналогичен key_pressed_hook, но вызывается только когда
** клавиша была нажата И отпущена.
**
** Следующий ключ сопоставлен:
** 'esc' (53) = выйти из программы
** 'p' (35) = ПСИХЕДИЧЕСКИЙ МОД!
** 'c' (8) = переключение режимов цвета
** 's' (1) = цветной сюрприз!
** 'd' (2) = психоделический сюрприз!
** 'l' (37) = линейный непрерывный цветовой режим
** 'f' (3) = остановить отслеживание курсора мыши для интерактивных фракталов
** 'r' (15) = сбросить фрактал обратно к исходному размеру окна, ограничениям iter и
**	цветовая палитра
*/

int			keydown_hook(int key, t_envars *env)
{
	if (key == 53)
	{
		cleanup_env(env);
		exit(0);
	}
	if (key == 35)
		env->psychedelic = (env->psychedelic) ? 0 : 1;
	if (key == 8)
		toggle_palette(env);
	if (key == 1)
		color_surprise(env);
	if (key == 2)
		psychedelic_surprise(env);
	if (key == 37 && env->psychedelic == 0)
		env->ccolor = (env->ccolor) ? 0 : 1;
	if (key == 3)
		env->mouse.freeze = (env->mouse.freeze) ? 0 : 1;
	if (key == 15)
		reset_env(env);
	if (key == 37 || key == 15 || key == 8 || key == 1)
		render(env);
	return (0);
}

/*
** key_pressed_hook - когда любая из клавиш со стрелками на клавиатуре
** удерживая, сдвиньте карту в этом направлении.
**
** ← (123) = перевести x влево обратно пропорционально увеличению
** → (124) = перевести x вправо обратно пропорционально увеличению
** ↓ (125) = перевести y вниз обратно пропорционально увеличению
** ↑ (126) = перевести y обратно обратно пропорционально увеличению
*/
int			key_pressed_hook(int key, t_envars *env)
{
	if (env->psychedelic == 0 && key != 53)
	{
		if (key == 124)
			env->x_t -= (0.05 / env->f.z_factor);
		if (key == 123)
			env->x_t += (0.05 / env->f.z_factor);
		if (key == 126)
			env->y_t += (0.05 / env->f.z_factor);
		if (key == 125)
			env->y_t -= (0.05 / env->f.z_factor);
		if (key == 24)
			env->iter_lim += 10;
		if (key == 27)
			env->iter_lim -= (env->iter_lim > 10) ? 10 : 0;
		render(env);
	}
	return (0);
}
