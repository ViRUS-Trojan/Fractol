/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:01:19 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/21 19:02:05 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "fractol.h"


/*
** Настраиваем таблицу переходов, чтобы мы могли получить правильную фрактальную функцию!
*/

static void		setup_fract_table(t_fract_jt j_table[25])
{
	j_table[0] = &julia;
	j_table[1] = &mandelbrot;
	j_table[2] = &mandelbrot;
	j_table[3] = &julia;
	j_table[4] = &mandelbrot;
	j_table[5] = &mandelbrot;
	j_table[6] = &julia;
	j_table[7] = &mandelbrot;
	j_table[8] = &mandelbrot;
}

static void		setup_fract_setup_table(t_f_set_jt j_table[25])
{
	j_table[0] = &setup_julia;
	j_table[1] = &setup_mandelbrot;
	j_table[2] = &setup_bship;
}

/*
** get_func () - настраиваем таблицу переходов, чтобы мы могли получить соответствующий фрактал
** функция, которую мы хотели бы отобразить.
**
** Мы делаем нашу перемычку статической, поэтому нам нужно устанавливать ее только один раз за
** нашу фрактальную программу.
**
** Нам нужно защитить нашу таблицу переходов, убедившись, что наше преобразованное число
** действительно допустимый индекс в таблице переходов!
*/

int				get_fract_funct(void *environ, char *choice_str)
{
	static t_fract_jt	fractal_jt[25] = {NULL};
	static t_f_set_jt	fract_setup_jt[25] = {NULL};
	int					choice;
	char				*itoa_choice;
	t_envars			*env;

	env = (t_envars *)environ;
	if (fractal_jt[0] == NULL)
		setup_fract_table(fractal_jt);
	if (fract_setup_jt[0] == NULL)
		setup_fract_setup_table(fract_setup_jt);
	choice = ft_atoi(choice_str);
	itoa_choice = ft_itoa(choice);
	if ((choice >= 0 && choice < 9) && ft_strcmp(itoa_choice, choice_str) == 0)
	{
		env->fract_func = fractal_jt[choice];
		env->fract_setup = fract_setup_jt[choice];
		free(itoa_choice);
		return (choice);
	}
	else
	{
		free(itoa_choice);
		return (-1);
	}
}