/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 10:18:21 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*lol;

	if (!(lol = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	if (size == 0)
		return (NULL);
	ft_bzero(lol, size);
	return (lol);
}
