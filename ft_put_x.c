/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:03:24 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/22 21:49:01 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_put_dash_flag_off(char *str, t_pritnt *tab,
		size_t strlen, char x)
{
	size_t	i;
	size_t	tlen;

	i = 0;
	tlen = 0;
	if (tab->sharp_flag == 1 && *str != '0')
	{
		if (x == 'x')
			tlen += write(1, "0x", 2);
		else
			tlen += write(1, "0X", 2);
	}
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	if (tab->pre == 0 && *str == '0')
		tlen += write(1, "", 1);
	while (tab->zero_pad-- > 0)
		tlen += write(1, "0", 1);
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	return (tlen);
}

static size_t	ft_put_dash_flag_on(char *str, t_pritnt *tab,
		size_t strlen, char x)
{
	size_t	i;
	size_t	tlen;

	i = 0;
	tlen = 0;
	if (tab->pre == 0 && *str == '0')
		tlen += write(1, "", 1);
	while (tab->zero_pad-- > 0)
		tlen += write(1, "0", 1);
	if (tab->sharp_flag == 1 && *str != '0')
	{
		if (x == 'x')
			tlen += write(1, "0x", 2);
		else
			tlen += write(1, "0X", 2);
	}
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}

static void	ft_get_padding(t_pritnt *tab, size_t strlen)
{
	if (tab->zero_flag == 1 && tab->pre == -1)
	{
		if (tab->sharp_flag == 1)
			strlen += 2;
		if (tab->sharp_flag == 1)
			tab->zero_pad = tab->wdt - strlen;
		else
			tab->zero_pad = tab->wdt - strlen;
	}
	else
	{
		tab->zero_pad = tab->pre - strlen;
		if (tab->sharp_flag == 1)
		{
			tab->pre += 2;
			strlen += 2;
		}
		if (tab->zero_pad > 0)
			tab->space_pad = tab->wdt - tab->pre;
		else
			tab->space_pad = tab->wdt - strlen;
	}
}

size_t	ft_put_hex(unsigned int num, t_pritnt *tab, char x)
{
	size_t	strlen;
	int		tlen;
	char	*str;

	if (x == 'x')
		str = ft_ultoa_base(num, 16, "0123456789abcdef");
	else
		str = ft_ultoa_base(num, 16, "0123456789ABCDEF");
	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	ft_get_padding(tab, strlen);
	tlen = 0;
	if (tab->dash_flag == 1)
		tlen += ft_put_dash_flag_on(str, tab, strlen, x);
	else
		tlen += ft_put_dash_flag_off(str, tab, strlen, x);
	free(str);
	return (tlen);
}
