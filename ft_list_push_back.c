/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 10:45:42 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 11:01:00 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, int flag)
{
	t_list	*tmp;

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
		ft_list_push_back(&((*begin_list)->next));
}
