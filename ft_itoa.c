/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 09:50:53 by thifranc          #+#    #+#             */
/*   Updated: 2016/02/20 16:29:44 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(int n)
{
	if (0 <= n && n <= 9)
		return (1);
	else
		return (1 + ft_nb_len(n / 10));
}

static void	ft_print(char *out, int nb, int i)
{
	int x;

	x = 0;
	if (i == 2)
		nb++;
	if (i == 1 || i == 2)
	{
		out[x] = '-';
		x++;
		nb = -nb;
	}
	while (nb != 0)
	{
		out[x] = nb % 10 + 48;
		nb /= 10;
		x++;
	}
	if (i == 2)
		out[1] = '8';
}

static char	*ft_strrev_nb(int nb, int flag, char *out)
{
	int		i;
	int		j;
	char	back;

	i = 0;
	if (flag == 1 || flag == 2)
		i++;
	j = ft_nb_len(nb) - 1 + i;
	while (i < j / 2 + 1)
	{
		back = out[i];
		out[i] = out[j - i];
		out[j - i] = back;
		i++;
	}
	out[ft_nb_len(nb) + flag] = '\0';
	return (out);
}

char		*ft_itoa(int n)
{
	int		flag;
	char	*out;

	flag = 0;
	if (n < 0)
		flag = 1;
	if (n == -2147483648)
		flag = 2;
	if (!(out = (char*)malloc(sizeof(char) * (ft_nb_len(n) + flag + 1))))
		return (NULL);
	if (n == 0)
	{
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
	ft_print(out, n, flag);
	ft_strrev_nb(n, flag, out);
	return (out);
}
