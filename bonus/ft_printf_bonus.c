/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:03:04 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/27 14:18:16 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_type(va_list lst, t_flag *flag)
{
	if (flag->type == '%')
		ft_putchar_flag('%', flag);
	else if (flag->type == 'c')
		ft_putchar_flag(va_arg(lst, int), flag);
	else if (flag->type == 's')
		ft_putstr_flag(va_arg(lst, char *), flag);
	else if (flag->type == 'p')
		ft_dir(va_arg(lst, unsigned long), flag);
	else if (flag->type == 'd' || flag->type == 'i')
		ft_di(va_arg(lst, int), flag);
	else if (flag->type == 'u')
		ft_u(va_arg(lst, unsigned int), flag);
	else if (flag->type == 'x' || flag->type == 'X')
		ft_xx(va_arg(lst, unsigned int), flag);
	else if (flag->type)
		ft_putchar_flag(flag->type, flag);
}

static void	ft_read(va_list lst, char *s, t_flag *flag)
{
	while (*s && !flag->error)
	{
		if (*s == '%')
		{
			s++;
			get_flags(&s, flag);
			flag->type = *s;
			ft_type(lst, flag);
		}
		else
			ft_putchar(*s, flag);
		if (*s)
			s++;
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	t_flag	flag;

	if (!s)
		return (-1);
	flag = init_struct();
	va_start(lst, s);
	ft_read(lst, (char *)s, &flag);
	va_end(lst);
	if (flag.error)
		return (-1);
	return (flag.length);
}
