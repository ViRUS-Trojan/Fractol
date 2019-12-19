/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:47:50 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/19 18:49:05 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mouse(t_envars *env)
{
	t_mouse		*new_mouse;

	new_mouse = &env->mouse;
	new_mouse->is_pressed = 0;
	new_mouse->freeze = 0;
	new_mouse->prev_x = 0;
	new_mouse->prev_y = 0;
	new_mouse->x = 0;
	new_mouse->y = 0;
	new_mouse->x_ratio = 0.5;
	new_mouse->y_ratio = 0.5;
}


/*
** mouse_pressed_hook - ловушка для события нажатия мыши, которое передается
** mlx_hook (). mlx_hook () передаст "int button, int x, int y", а затем
** любые параметры также передаются в mlx_hook () функции, когда мышь
** нажата.
**
** Кнопка может принимать несколько значений !!!
** 1 = щелчок левой кнопкой мыши
** 2 = щелчок правой кнопкой мыши
** 3 = ????? (может быть, нажав колесо прокрутки ???)
** 4 = колесо прокрутки мыши вниз - уменьшить коэффициент масштабирования
** 5 = колесо прокрутки мыши вверх - увеличить коэффициент масштабирования
** 6 = колесо прокрутки мыши вправо
** 7 = колесо прокрутки мыши влево
**
** ПРИМЕЧАНИЕ: все координаты x и y, сообщаемые функциям подключения мыши, будут
** иметь (0, 0) как нижний левый угол окна. (WIN_W, WIN_H) будет
** таким образом, будет верхний правый угол окна ... что совершенно другое
** из изображения (0,0), которое является верхним левым углом ... перейти к рисунку ...
**
** ПРИМЕЧАНИЕ: НЕ ПЫТАЙТЕСЬ ИЗМЕНИТЬ ТИПЫ ПАРАМЕТРОВ X & Y ОТ INT ДЛЯ ДВОЙНОГО !!
** Это повредит адресацию ваших параметров и даст вам segfaults
** это займет у вас, возможно, несколько часов для отладки (по крайней мере для меня ...)
*/

int		mouse_pressed_hook(int button, int x, int y, t_envars *env)
{
	double		fx;
	double		fy;
	t_mouse		*mouse;

	mouse = &env->mouse;
	if (x >= 0 && x <= env->w && y >= 0 && y <= env->h)
	{
		if (button == 4 || button == 5)
		{
			mouse->x_ratio = (double)x / env->w;
			mouse->y_ratio = (double)y / env->h;
			fx = ft_lint(env->f.x_min, env->f.x_max, mouse->x_ratio);
			fy = ft_lint(env->f.y_min, env->f.y_max, mouse->y_ratio);
			if (button == 4)
				env->f.z_factor /= 1.1;
			if (button == 5)
				env->f.z_factor *= 1.1;
			env->f.x_cent = fx;
			env->f.y_cent = fy;
			env->x_t = 0;
			env->y_t = 0;
			render(env);
		}
	}
	return (0);
}


/*
** ПРИМЕЧАНИЕ: НЕ ПЫТАЙТЕСЬ ИЗМЕНИТЬ ТИПЫ ПАРАМЕТРОВ X & Y ОТ INT ДЛЯ ДВОЙНОГО !!
*/

int		mouse_released_hook(int button, int x, int y, t_envars *env)
{
	t_mouse		*mouse;

	mouse = &env->mouse;
	(void)button;
	(void)x;
	(void)y;
	mouse->is_pressed = 0;
	return (0);
}

/*
** ПРИМЕЧАНИЕ: НЕ ПЫТАЙТЕСЬ ИЗМЕНИТЬ ТИПЫ ПАРАМЕТРОВ X & Y ОТ INT ДЛЯ ДВОЙНОГО !!
*/

int		mouse_moved_hook(int x, int y, t_envars *env)
{
	t_mouse		*mouse;
	int			f_i;

	mouse = &env->mouse;
	f_i = env->f.interactive;
	if (mouse->freeze == 0 && (x >= 0 && x <= env->w && y >= 0 && y <= env->h))
	{
		mouse->prev_x = mouse->x;
		mouse->prev_y = mouse->y;
		mouse->x = x;
		mouse->y = y;
		if (env->psychedelic == 0 && f_i == 1)
			render(env);
	}
	return (0);
}
