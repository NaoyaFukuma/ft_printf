/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:13:47 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/18 21:27:03 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_output_conversion(const char *fmt, t_pritnt *tab)
{
	if (*fmt == '%')
		return (write(1, "%", 1));
	if (*fmt == 'c')
		return (ft_put_c(va_arg(tab->argp, int), tab));
	if (*fmt == 's')
		return (ft_put_s(va_arg(tab->argp, char *), tab));
	if (*fmt == 'd' || *fmt == 'i')
		return (ft_put_d_i(va_arg(tab->argp, int), tab));
	if (*fmt == 'u')
		return (ft_put_unsigned_d(va_arg(tab->argp, unsigned int), tab));
	if (*fmt == 'x' || *fmt == 'X')
		return (ft_put_hex(va_arg(tab->argp, unsigned int), tab, *fmt));
	if (*fmt == 'o')
		return (ft_put_oct(va_arg(tab->argp, unsigned int), tab));
	if (*fmt == 'p')
		return (ft_put_p(va_arg(tab->argp, unsigned long), tab));
	return (0);
}

static const char	*ft_input_tab(const char *fmt, t_pritnt *tab)
{
	ft_parse_skip_flag(&fmt, tab);
	ft_parse_skip_wdt(&fmt, tab);
	ft_parse_skip_pre(&fmt, tab);
	return (fmt);
}

void	ft_init_tab(t_pritnt *tab)
{
	tab->sharp_flag = 0;
	tab->zero_flag = 0;
	tab->dash_flag = 0;
	tab->plus_flag = 0;
	tab->space_flag = 0;
	tab->wdt = -1;
	tab->pre = -1;
	tab->space_pad = 0;
	tab->zero_pad = 0;
	return ;
}

int	ft_printf(const char *fmt, ...)
{
	t_pritnt	tab;
	size_t		tlen;

	tlen = 0;
	va_start(tab.argp, fmt);
	while (*fmt != '\0')
	{
		ft_init_tab(&tab);
		if (*fmt != '%')
			tlen += write(1, fmt, 1);
		else
		{
			fmt = ft_input_tab(fmt + 1, &tab);
			tlen += ft_output_conversion(fmt, &tab);
		}
		if (tlen >= INT_MAX)
			return (-1);
		fmt++;
	}
	va_end(tab.argp);
	return ((int)tlen);
}
