/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:03:02 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:32:50 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chr_pos(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	int		size;
	char	*copy;

	i = ft_strlen(s1);
	size = i;
	if (i > n)
		size = n;
	if (!(copy = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_putnstr(char *str, int n)
{
	int size;
	int len;

	len = ft_strlen(str);
	if (n >= len)
		size = len;
	if (len > n)
		size = n;
	write(1, str, size);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
