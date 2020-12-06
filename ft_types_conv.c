/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:46:40 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:30:50 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convchar(va_list arg, t_parse *f)
{
	char *to_conv;

	to_conv = malloc(sizeof(char) * 2);
	to_conv[1] = '\0';
	if (f->conversion == 8)
		to_conv[0] = '%';
	else
		to_conv[0] = va_arg(arg, int);
	if (f->enlarge < 1)
		f->enlarge = 1;
	f->truncate = 1;
	to_conv = ft_strdup_conv(to_conv, f);
	write(1, to_conv, f->enlarge);
	free(to_conv);
}

void	ft_convstr(va_list arg, t_parse *f)
{
	char	*to_conv;

	to_conv = va_arg(arg, char*);
	if (!to_conv)
		to_conv = ft_strdup("(null)");
	else
		to_conv = ft_strdup(to_conv);
	if (!f->precision || f->truncate > ft_strlen(to_conv))
		f->truncate = ft_strlen(to_conv);
	if (f->width_len < f->truncate)
		f->enlarge = f->truncate;
	else
		f->enlarge = f->width_len;
	to_conv = ft_strdup_conv(to_conv, f);
	ft_putnstr(to_conv, f->enlarge);
	free(to_conv);
}

void	ft_convint(va_list arg, t_parse *f)
{
	long nb;
	char *to_conv;

	nb = (long)va_arg(arg, int);
	if (nb == 0 && f->precision && f->precision_len == 0)
		f->is_invisible_zero = 1;
	if (nb < 0)
	{
		f->is_neg = 1;
		nb *= -1;
	}
	to_conv = ft_itoa(nb);
	if (f->precision_len > ft_strlen(to_conv))
		to_conv = ft_int_precision(to_conv, *f);
	if (f->is_neg && (f->fuller != '0' || f->width_len <= ft_strlen(to_conv)))
		to_conv = ft_strjoin("-", to_conv, 0, 1);
	if (!f->is_invisible_zero)
		f->truncate = ft_strlen(to_conv);
	if (f->width_len < ft_strlen(to_conv) && !f->is_invisible_zero)
		f->enlarge = ft_strlen(to_conv);
	to_conv = ft_strdup_conv(to_conv, f);
	if (f->is_neg && f->fuller == '0')
		to_conv[0] = '-';
	ft_putnstr(to_conv, f->enlarge);
	free(to_conv);
}

void	ft_convuint(va_list arg, t_parse *f)
{
	char	*to_conv;
	long	nb;

	nb = (long)va_arg(arg, unsigned int);
	if (nb == 0 && f->precision && f->precision_len == 0)
		f->is_invisible_zero = 1;
	if (f->conversion == 4)
		to_conv = ft_itobase(nb, "0123456789");
	if (f->conversion == 5)
		to_conv = ft_itobase(nb, "0123456789abcdef");
	if (f->conversion == 6)
		to_conv = ft_itobase(nb, "0123456789ABCDEF");
	if (f->precision_len > ft_strlen(to_conv))
		to_conv = ft_int_precision(to_conv, *f);
	if (!f->is_invisible_zero)
		f->truncate = ft_strlen(to_conv);
	if (f->width_len < ft_strlen(to_conv) && !f->is_invisible_zero)
		f->enlarge = ft_strlen(to_conv);
	to_conv = ft_strdup_conv(to_conv, f);
	ft_putnstr(to_conv, f->enlarge);
	free(to_conv);
}

void	ft_convadd(va_list arg, t_parse *f)
{
	char *to_conv;

	to_conv = ft_itobase(va_arg(arg, unsigned long), "0123456789abcdef");
	if ((to_conv[0] == '0') && f->precision && f->precision_len == 0)
		f->is_invisible_zero = 1;
	if (f->precision_len > ft_strlen(to_conv))
		to_conv = ft_int_precision(to_conv, *f);
	to_conv = ft_strjoin("0x", to_conv, 0, 1);
	if (!f->is_invisible_zero)
		f->truncate = ft_strlen(to_conv);
	if (f->width_len < ft_strlen(to_conv) && !f->is_invisible_zero)
		f->enlarge = ft_strlen(to_conv);
	if (f->is_invisible_zero)
	{
		f->truncate = 2;
		if (f->width_len < ft_strlen(to_conv))
			f->enlarge = 2;
	}
	to_conv = ft_strdup_conv(to_conv, f);
	ft_putnstr(to_conv, f->enlarge);
	free(to_conv);
}
