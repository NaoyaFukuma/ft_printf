/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:16:19 by nfukuma           #+#    #+#             */
/*   Updated: 2022/07/18 22:36:50 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_skip_atoi(const char **fmt)
{
	int	res_int;

	res_int = 0;
	while (ft_isdigit(**fmt))
	{
		res_int = res_int * 10 + **fmt - '0';
		(*fmt)++;
	}
	return (res_int);
}

void	ft_parse_skip_pre(const char **fmt, t_pritnt *tab)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		tab->pre = 0;
		tab->zero_flag = 0;
		if (ft_isdigit(**fmt))
			tab->pre = ft_skip_atoi(fmt);
		else if (**fmt == '*')
		{
			(*fmt)++;
			tab->pre = va_arg(tab->argp, int);
			if (tab->pre < 0)
				tab->pre = 0;
		}
	}
	return ;
}

void	ft_parse_skip_wdt(const char **fmt, t_pritnt *tab)
{
	if (ft_isdigit(**fmt))
		tab->wdt = ft_skip_atoi(fmt);
	else if (**fmt == '*')
	{
		(*fmt)++;
		tab->wdt = va_arg(tab->argp, int);
		if (tab->wdt < 0)
		{
			tab->dash_flag = 1;
			tab->wdt *= -1;
		}
	}
	return ;
}

void	ft_parse_skip_flag(const char **fmt, t_pritnt *tab)
{
	while (**fmt == '#' || **fmt == '0' || **fmt == '-' || **fmt == '+'
		|| **fmt == ' ')
	{
		if (**fmt == '#')
			tab->sharp_flag = 1;
		if (**fmt == '0')
			tab->zero_flag = 1;
		if (**fmt == '-' && tab->zero_flag != 1)
			tab->dash_flag = 1;
		if (**fmt == '+')
			tab->plus_flag = 1;
		if (**fmt == ' ')
			tab->space_flag = 1;
		(*fmt)++;
	}
	return ;
}
