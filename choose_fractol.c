/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:01:19 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/16 19:49:50 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "fractol.h"


/*
** Настраиваем таблицу переходов, чтобы мы могли получить правильную фрактальную функцию!
*/

static void     setup_fract_tablet(t_fract_jt j_tablet[25])
{
    
}

static void     setup_fract_setup_tablet(t_f_set_jt j_tablet[25])
{

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

int             get_fract_func(void *environ, char *choice_str)
{

}