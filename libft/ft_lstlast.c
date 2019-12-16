/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdelsie <vdelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:44:28 by vdelsie           #+#    #+#             */
/*   Updated: 2019/12/15 18:44:29 by vdelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list	*curr_list;

	curr_list = begin_list;
	if (curr_list)
	{
		while (curr_list->next)
		{
			curr_list = curr_list->next;
		}
	}
	return (curr_list);
}
