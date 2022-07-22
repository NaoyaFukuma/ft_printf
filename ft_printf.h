/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:38:28 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/19 16:36:44 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	argp;
	int		sharp_flag;
	int		zero_flag;
	int		dash_flag;
	int		plus_flag;
	int		space_flag;
	int		wdt;
	int		pre;
	int		space_pad;
	int		zero_pad;
}			t_pritnt;

// in ft_input_utils.c
int			ft_skip_atoi(const char **fmt);
void		ft_parse_skip_flag(const char **fmt, t_pritnt *tab);
void		ft_parse_skip_wdt(const char **fmt, t_pritnt *tab);
void		ft_parse_skip_pre(const char **fmt, t_pritnt *tab);

//in ft_output_utils.c
size_t		ft_put_c(char c, t_pritnt *tab);
size_t		ft_put_s(char *str, t_pritnt *tab);
size_t		ft_put_d_i(int num, t_pritnt *tab);
size_t		ft_put_unsigned_d(unsigned int num, t_pritnt *tab);
size_t		ft_put_hex(unsigned int num, t_pritnt *tab, char x);
size_t		ft_put_oct(unsigned int num, t_pritnt *tab);
size_t		ft_put_p(unsigned long num, t_pritnt *tab);

// in ft_printf.c
int			ft_printf(const char *fmt, ...);

#endif
