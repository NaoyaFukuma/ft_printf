/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:32:13 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/22 21:48:18 by nfukuma          ###   ########.fr       */
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
	while (tab->zero_pad-- > 0)
		tlen += write(1, "0", 1);
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}

static void	ft_get_padding(t_pritnt *tab, size_t strlen)
{
	if (tab->zero_flag == 1 && tab->pre == -1)
		tab->zero_pad = tab->wdt - strlen;
	else
	{
		tab->zero_pad = tab->pre - strlen;
		if (tab->zero_pad > 0)
			tab->space_pad = tab->wdt - tab->pre;
		else
			tab->space_pad = tab->wdt - strlen;
	}
}

size_t	ft_put_unsigned_d(unsigned int num, t_pritnt *tab)
{
	size_t	strlen;
	size_t	tlen;
	char	*str;

	str = ft_ultoa(num);
	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	ft_get_padding(tab, strlen);
	tlen = 0;
	if (tab->dash_flag == 1)
		tlen += ft_put_dash_flag_on(num, str, tab, strlen);
	else
		tlen += ft_put_dash_flag_off(num, str, tab, strlen);
	free(str);
	return (tlen);
}
