/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:44:37 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/20 18:06:12 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>
#include "fractol.h"

static void		disp_info(int mode)
{
	if (mode == 0)
	{
		write(2, "Usage: ./fractol [fractol option]\n\n", 35);
		write(2, "Fractol options (use number, not name!):\n", 41);
		write(2, "0) Julia\n1) Mandelbrot\n2) Burning Ship\n", 39);
		write(2, "3) Trijulia\n4) Tribrot\n5) Excalibur\n", 36);
		write(2, "6) Quadjulia\n7) Quadrobrot\n8) Ghosts\n", 36);
		write(2, "\nExample: './fractol 0' - Displays Julia set\n\n", 46);
	}
	else if (mode == 1)
	{
		ft_putstr("\n				Fract'ol 21!!\n\
		Прокрутка мыши вверх / вниз: увеличение / уменьшение @ положения мыши \ n \
		Клавиши со стрелками: перевести реальные / мнимые оси \ n \
		'+/-': увеличить / уменьшить предел итерации \ n \
		f: заморозить отслеживание курсора мыши (работает только для фракталов типа Юлия!) \ n \
		p: психоделический режим! \ n \
		l: линейный непрерывный цветовой режим \ n \
		c: переключить цветовые палитры \ n \
		s: Цвет сюрприз! \ n \
		d: психоделический сюрприз! \ n \
		r: сбросить активный фрактал! \ n \
		esc: Quit: (\ n \ n ");
	}
}

void			start_hooks(t_envars *env)
{
	mlx_key_hook(env->win, keydown_hook, env);
	mlx_hook(env->win, 2, 0, key_pressed_hook, env);
	mlx_hook(env->win, 4, 0, mouse_pressed_hook, env);
	mlx_hook(env->win, 5, 0, mouse_released_hook, env);
	mlx_hook(env->win, 6, 0, mouse_moved_hook, env);
	mlx_loop_hook(env->mlx, loop_hook, env);
}

void			setup_env(t_envars *env)
{
	env->w = 1024;
	env->h = 576;
	env->size = env->w * env->h;
	env->x_t = 0;
	env->y_t = 0;
	env->ccolor = 0;
	env->iter_lim = 50;
	env->iter_buf = (float *)malloc(env->size * sizeof(float));
	env->fract_setup(env);
	setup_color(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w, env->h, "Fractol 42");
	init_img(env);
	init_mouse(env);
	start_hooks(env);
	render(env);
	mlx_loop(env->mlx);
}


/*
** main - функция, с которой мы начинаем нашу сессию mlx
** Есть дополнительные крючки, которые можно найти!
** См .: https://github.com/qst0/ft_libgfx.
** Особый интерес представляют крючки для нажатия, отпускания и перемещения мыши
** которые сопоставлены с 4, 5 и 6 соответственно.
*/

int				main(int argc, char *argv[])
{
	t_envars	env;

	env.fract_choice = -1;
	if (argc == 2 && (env.fract_choice = get_fract_funct(&env, argv[1])) != -1)
	{
		disp_info(1);
		setup_env(&env);
		return (0);
	}
	else
	{
		disp_info(0);
		return (1);
	}
}
