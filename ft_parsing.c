/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:40:25 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:27:41 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parseprecision(char *format, t_parse *f, va_list arg)
{
	int i;

	i = 0;
	f->precision = 1;
	format++;
	if (*format == '*')
	{
		f->precision_len = va_arg(arg, int);
		format++;
	}
	else if (*format >= '0' && *format <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		f->precision_len = ft_natoi(format, i);
		format += i;
	}
	if (f->precision_len < 0)
	{
		f->precision = 0;
		f->precision_len = 0;
	}
	if (f->precision == 1)
		f->zero = 0;
	return (format);
}

char	*ft_parsewidth(char *format, t_parse *f, va_list arg)
{
	int i;

	i = 0;
	if (*format == '*')
	{
		f->width = 1;
		f->width_len = va_arg(arg, int);
		format++;
	}
	else if (*format >= '0' && *format <= '9')
	{
		while (format[i] >= '0' && format[i] <= '9')
			i++;
		f->width = 1;
		f->width_len = ft_natoi(format, i);
		format += i;
	}
	if (f->width_len < 0)
	{
		f->minus = 1;
		f->width_len *= -1;
	}
	return (format);
}

char	*ft_parseconv(char *format, t_parse *f)
{
	char	*conv;

	conv = "csdiuxXp%";
	f->conversion = ft_chr_pos(*format, conv);
	f->fuller = ' ';
	if (f->zero && !f->minus)
		f->fuller = '0';
	if ((f->conversion == 2 || f->conversion == 3) && f->precision)
		f->fuller = ' ';
	format++;
	return (format);
}

char	*ft_parse(char *str, va_list arg, t_parse *f)
{
	ft_memset(f, 0, sizeof(t_parse));
	str++;
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			f->minus = 1;
		if (*str == '0')
			f->zero = 1;
		str++;
	}
	if (*str == '*' || (*str >= '0' && *str <= '9'))
		str = ft_parsewidth(str, f, arg);
	if (*str == '.')
		str = ft_parseprecision(str, f, arg);
	str = ft_parseconv(str, f);
	f->enlarge = f->width_len;
	f->truncate = f->precision_len;
	return (str);
}
