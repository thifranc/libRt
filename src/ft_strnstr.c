/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:53:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:20 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t nb)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && i <= (len - nb))
	{
		if (ft_strncmp((char*)s1 + i, (char*)s2, len) == 0)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
