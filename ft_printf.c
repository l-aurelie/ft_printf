/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:56:44 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:26:13 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_displaystr(char *str, int *size)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			break ;
		i++;
	}
	ft_putnstr(str, i);
	*size += i;
	return (str + i);
}

int		ft_conv_ok(char **s)
{
	(*s)++;
	while (**s && (**s == '-' || **s == '0'))
		(*s)++;
	if (**s == '*')
		(*s)++;
	else if (**s >= '0' && **s <= '9')
	{
		while (**s && (**s >= '0' && **s <= '9'))
			(*s)++;
	}
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
			(*s)++;
		else if (**s && (**s >= '0' && **s <= '9'))
		{
			while (**s && (**s >= '0' && **s <= '9'))
				(*s)++;
		}
	}
	if (**s == 'c' || **s == 's' || **s == 'd' || **s == 'i' || **s == 'u'
		|| **s == 'x' || **s == 'X' || **s == 'p' || **s++ == '%')
		return (1);
	return (0);
}

int		ft_format_ok(char *str)
{
	while (*str)
	{
		if (*str != '%')
		{
			while (*str && *str != '%')
				str++;
		}
		else
		{
			if (!ft_conv_ok(&str))
				return (0);
			str++;
		}
	}
	return (1);
}

int		ft_printf(char *str, ...)
{
	va_list	arg;
	int		size;
	t_parse f;

	if (!ft_format_ok(str))
		return (-1);
	va_start(arg, str);
	size = 0;
	while (*str)
	{
		if (*str != '%')
		{
			str = ft_displaystr(str, &size);
		}
		else
		{
			str = ft_parse(str, arg, &f);
			ft_displayconv(arg, &f, &size);
		}
	}
	va_end(arg);
	return (size);
}
