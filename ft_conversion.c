/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:52:47 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:29:32 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_conv(char *to_conv, t_parse *f)
{
	char	*print;
	int		i;

	i = 0;
	print = malloc(sizeof(char) * (f->enlarge + 1));
	if (!print)
		return (NULL);
	if (f->minus)
	{
		if (f->conversion == 0)
			ft_memcpy(print, to_conv, f->truncate);
		else
			ft_strncpy(print, to_conv, f->truncate);
		while (f->truncate < f->enlarge)
			print[f->truncate++] = f->fuller;
		print[f->truncate] = '\0';
	}
	else
	{
		while (i < (f->enlarge - f->truncate))
			print[i++] = f->fuller;
		ft_strncpy(print + i, to_conv, f->enlarge - i);
	}
	free(to_conv);
	return (print);
}

char	*ft_int_precision(char *to_conv, t_parse f)
{
	f.minus = 0;
	f.enlarge = f.precision_len;
	f.truncate = ft_strlen(to_conv);
	f.fuller = '0';
	to_conv = ft_strdup_conv(to_conv, &f);
	return (to_conv);
}

void	ft_displayconv(va_list arg, t_parse *f, int *size)
{
	void (*conv[10])();

	conv[0] = &ft_convchar;
	conv[1] = &ft_convstr;
	conv[2] = &ft_convint;
	conv[3] = &ft_convint;
	conv[4] = &ft_convuint;
	conv[5] = &ft_convuint;
	conv[6] = &ft_convuint;
	conv[7] = &ft_convadd;
	conv[8] = &ft_convchar;
	(*conv[f->conversion])(arg, f);
	*size += f->enlarge;
}
