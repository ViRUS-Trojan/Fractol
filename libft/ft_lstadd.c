/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:44:01 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/15 18:44:03 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
	}
}
