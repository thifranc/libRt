/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 08:50:07 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:28:39 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *c))
{
	int i;

	i = 0;
	while (s[i])
	{
		f(&s[i]);
		i++;
	}
}
