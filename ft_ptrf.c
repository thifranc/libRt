/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 11:50:27 by thifranc          #+#    #+#             */
/*   Updated: 2017/10/24 14:09:08 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define LEFT_PADDING 1
#define ZERO_FILL 2
#define HEXA 4
#define PADDING 8

char	*do_nb(int opt, int max, va_list va)
{
	char				*out;
	long long int		arg;
	int					i;
	int					base;
	char				*base_str;

	i = 0;
	base = opt & HEXA ? 16 : 10;
	base_str = opt & HEXA ? "0123456789abcdef" : "0123456789";
	arg = va_arg(va, long long int);
	max = opt & PADDING ? va_arg(va, int) : ft_nb_len_base(arg, base);
	if (!(out = malloc(max + 1)))
		return (NULL);
	out[max] = '\0';
	while (i < max)
		out[i++] = opt & ZERO_FILL ? '0' : ' ';
	i = opt & LEFT_PADDING ? ft_nb_len_base(arg, base) : max;
	if (arg == 0)
		out[--i] = '0';
	while (arg)
	{
		out[--i] = base_str[arg % base];
		arg /= base;
	}
	return (out);
}

char	*do_string(int opt, int max, va_list va)
{
	char	*out;
	char	*arg;
	int		i;
	int		len;

	i = 0;
	arg = va_arg(va, char *);
	len = ft_strlen(arg);
	max = opt & PADDING ? va_arg(va, int) : len;
	if (!(out = malloc(max + 1)))
		return (NULL);
	out[max] = '\0';
	while (i < max)
		out[i++] = opt & ZERO_FILL ? '0' : ' ';
	i = opt & LEFT_PADDING ? len : max;
	while (len > 0)
		out[--i] = arg[--len];
	return (out);
}

char	*get_opt_and_arg(char **s, va_list va)
{
	int		opt;
	int		max;

	opt = 0;
	max = 0;
	(*s)++;
	while (**s != 's' && **s != 'x' && **s != 'd')
	{
		if (**s == '-')
			opt |= LEFT_PADDING;
		if (**s == '0')
			opt |= ZERO_FILL;
		if (**s == '*')
			opt |= PADDING;
		(*s)++;
	}
	if (**s == 's')
		return (do_string(opt, max, va));
	else if (**s == 'x')
	{
		opt |= HEXA;
		return (do_nb(opt, max, va));
	}
	else
		return (do_nb(opt, max, va));
}

char	*get_till_opt(char **str)
{
	int		i;
	char	*out;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if (!(out = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (**str && **str != '%')
	{
		out[i++] = **str;
		(*str)++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_ptrf(char *str, ...)
{
	va_list	va;
	char	*out;
	char	*tmp;
	char	*tmp2;

	va_start(va, str);
	out = NULL;
	while (*str)
	{
		tmp = get_till_opt(&str);
		if (!out)
			tmp2 = ft_strdup(out);
		else
			tmp2 = ft_strdup_del(out);
		out = ft_strjoin_del(tmp2, tmp, 2);
		if (*str && *str == '%')
		{
			tmp = get_opt_and_arg(&str, va);
			str++;
			tmp2 = ft_strdup_del(out);
			out = ft_strjoin_del(tmp2, tmp, 2);
		}
	}
	va_end(va);
	return (out);
}
