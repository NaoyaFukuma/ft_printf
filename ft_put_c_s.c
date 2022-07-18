/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:01:01 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/18 21:27:00 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_put_c(char c, t_pritnt *tab)
{
	size_t	tlen;

	tlen = 0;
	tab->space_pad = tab->wdt - 1;
	if (tab->dash_flag == 0)
		while (tab->space_pad-- > 0)
			tlen += write(1, " ", 1);
	tlen += write(1, &c, 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}

size_t	ft_put_s(char *str, t_pritnt *tab)
{
	size_t	strlen;
	size_t	tlen;

	if (str == NULL)
		str = "(null)";
	strlen = ft_strlen(str);
	if (tab->pre != -1 && tab->pre < strlen)
		strlen = tab->pre;
	if (tab->wdt != -1 && tab->wdt > strlen)
		tab->space_pad = tab->wdt - strlen;
	tlen = 0;
	if (tab->dash_flag == 0)
		while (tab->space_pad-- > 0)
			tlen += write(1, " ", 1);
	while (strlen--)
		tlen += write(1, str++, 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}
