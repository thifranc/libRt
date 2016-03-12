/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 10:45:42 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 10:46:28 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tri_push_back(t_tri **begin_list, int flag)
{
	t_tri	*tmp;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem();
	else if (((*begin_list)->next) == NULL)
	{
		(*begin_list)->next = ft_create_elem();
		tmp = (*begin_list)->next;
		if (flag == 1)
			tmp->prev = *begin_list;
	}
	else
		ft_tri_push_back(&((*begin_list)->next));
}
