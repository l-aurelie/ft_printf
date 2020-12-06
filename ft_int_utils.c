/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:59:43 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:31:51 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_natoi(const char *str, int n)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (i < n && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (i < n && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (i < n && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

char	*ft_size_str(long int nb, int len, int *i)
{
	char	*str;

	while (nb / len > 0)
	{
		nb = nb / len;
		*i = *i + 1;
	}
	str = malloc(sizeof(char) * (*i + 1));
	str[*i] = '\0';
	return (str);
}

char	*ft_itobase(unsigned long long nb_long, char *base_to)
{
	char		*result;
	int			len;
	int			i;
	int			neg_sign;

	len = ft_strlen(base_to);
	neg_sign = 0;
	i = 1;
	if (nb_long < 0)
	{
		nb_long = -nb_long;
		neg_sign = 1;
		i++;
	}
	result = ft_size_str(nb_long, len, &i);
	if (nb_long == 0)
		result[--i] = base_to[nb_long % len];
	while (nb_long != 0)
	{
		result[--i] = base_to[nb_long % len];
		nb_long = nb_long / len;
	}
	if (neg_sign)
		result[--i] = '-';
	return (result);
}
