/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:09:38 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/18 23:38:19 by nfukuma          ###   ########.fr       */
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
	tlen += write(1, "0x", 2);
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
	tlen += write(1, "0x", 2);
	while (i < strlen)
		tlen += write(1, &str[i++], 1);
	while (tab->space_pad-- > 0)
		tlen += write(1, " ", 1);
	return (tlen);
}

size_t	ft_put_p(unsigned long num, t_pritnt *tab)
{
	size_t	strlen;
	int		tlen;
	char	*str;

	str = ft_ultoa_base(num, 16, "0123456789abcdef");
	if (str == NULL)
		return (0);
	strlen = ft_strlen(str);
	tab->space_pad = tab->wdt - strlen - 2;
	tlen = 0;
	if (tab->dash_flag == 1)
		tlen += ft_put_dash_flag_on(num, str, tab, strlen);
	else
		tlen += ft_put_dash_flag_off(num, str, tab, strlen);
	free(str);
	return (tlen);
}
