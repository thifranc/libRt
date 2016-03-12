/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:39:05 by thifranc          #+#    #+#             */
/*   Updated: 2016/03/12 10:25:49 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return ((void*)&s2[i]);
		i++;
	}
	return (NULL);
}
