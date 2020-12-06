/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleconte <aleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:42:14 by aleconte          #+#    #+#             */
/*   Updated: 2020/12/06 15:46:47 by aleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_parse
{
	int		minus;
	int		zero;
	char	fuller;
	int		width;
	int		width_len;
	int		precision;
	int		precision_len;
	int		conversion;
	int		is_neg;
	int		is_invisible_zero;
	int		enlarge;
	int		truncate;
}				t_parse;

char			*ft_displaystr(char *str, int *size);
int				ft_conv_ok(char **s);
int				ft_format_ok(char *str);
int				ft_printf(char *str, ...);

char			*ft_parse(char *str, va_list arg, t_parse *f);
char			*ft_parseprecision(char *format, t_parse *f, va_list arg);
char			*ft_parsewidth(char *format, t_parse *f, va_list arg);
char			*ft_parseconv(char *format, t_parse *f);

char			*ft_strdup_conv(char *to_conv, t_parse *f);
char			*ft_int_precision(char *to_conv, t_parse f);
void			ft_displayconv(va_list arg, t_parse *f, int *size);

void			ft_convchar(va_list arg, t_parse *f);
void			ft_convstr(va_list arg, t_parse *f);
void			ft_convint(va_list arg, t_parse *f);
void			ft_convuint(va_list arg, t_parse *f);
void			ft_convadd(va_list arg, t_parse *f);

int				ft_natoi(const char *str, int n);
char			*ft_size_str(long int nb, int len, int *i);
char			*ft_itobase(unsigned long long nb_long, char *base_to);

int				ft_chr_pos(char c, char *str);
char			*ft_strndup(const char *s1, int n);
void			ft_putnstr(char *str, int n);
char			*ft_strncpy(char *dest, char *src, unsigned int n);

#endif
