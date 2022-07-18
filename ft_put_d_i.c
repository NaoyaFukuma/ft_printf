/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:50:32 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/18 21:28:54 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static size_t	ft_put_dash_flag_off(int num, char *str, t_pritnt *tab,
		size_t strlen)
{
	size_t	i;
	size_t	tlen;

	i = 0;
	tlen = 0;
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	if (tab->pre == 0 && num == 0)
		tlen += write(1, "", 1);
	if (num < 0)
		tlen += write(1, &str[i++], 1);
	else if (tab->plus_flag == 1)
		tlen += write(1, "+", 1);
	else if (tab->space_flag == 1)
		tlen += write(1, " ", 1);
	while (tab->zero_pad-- > 0)
		tlen += write(1, "0", 1);
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	return (tlen);
}

static size_t	ft_put_dash_flag_on(int num, char *str, t_pritnt *tab,
		size_t strlen)
{
	size_t	i;
	size_t	tlen;

	i = 0;
	tlen = 0;
	if (tab->pre == 0 && num == 0)
		tlen += write(1, "", 1);
	if (num < 0)
		tlen += write(1, &str[i++], 1);
	else if (tab->plus_flag == 1)
		tlen += write(1, "+", 1);
	else if (tab->space_flag == 1)
		tlen += write(1, " ", 1);
	while (tab->zero_pad-- > 0)
		tlen += write(1, "0", 1);
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}

static void	ft_get_padding(int num, t_pritnt *tab, size_t strlen)
{
	if (num >= 0 && (tab->plus_flag == 1 || tab->space_flag == 1))
		strlen++;
	if (tab->zero_flag == 1 && tab->pre == -1)
		tab->zero_pad = tab->wdt - strlen;
	else
	{
		if (num < 0 || tab->plus_flag == 1 || tab->space_flag == 1)
			tab->zero_pad = tab->pre - (strlen - 1);
		else
			tab->zero_pad = tab->pre - strlen;
		if (tab->zero_pad > 0)
		{
			if (num < 0 || tab->plus_flag == 1 || tab->space_flag == 1)
				tab->space_pad = tab->wdt - (tab->pre + 1);
			else
				tab->space_pad = tab->wdt - tab->pre;
		}
		else
			tab->space_pad = tab->wdt - strlen;
	}
}

size_t	ft_put_d_i(int num, t_pritnt *tab)
{
	size_t	i;
	size_t	strlen;
	size_t	tlen;
	char	*str;

	str = ft_itoa(num);
	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	i = 0;
	ft_get_padding(num, tab, strlen);
	tlen = 0;
	if (tab->dash_flag == 1)
		tlen += ft_put_dash_flag_on(num, str, tab, strlen);
	else
		tlen += ft_put_dash_flag_off(num, str, tab, strlen);
	free(str);
	return (tlen);
}
