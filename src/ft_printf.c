/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:24:22 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/02 13:15:48 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_read(char c, va_list lst, int len)
{
	int	x;

	x = 0;
	if (c == '%')
		x = ft_putchar('%');
	else if (c == 'c')
		x = ft_putchar(va_arg(lst, int));
	else if (c == 's')
		x = ft_putstr(va_arg(lst, char *));
	else if (c == 'p')
		x = ft_dir(va_arg(lst, unsigned long));
	else if (c == 'd' || c == 'i')
		x = ft_di(va_arg(lst, int));
	else if (c == 'u')
		x = ft_u(va_arg(lst, unsigned int));
	else if (c == 'x' || c == 'X')
		x = ft_xx(va_arg(lst, unsigned int), c);
	if (x == -1)
		return (-1);
	return (len + x);
}

int	ft_printf(char const *s, ...)
{
	va_list	lst;
	int		length;

	if (!s)
		return (-1);
	length = 0;
	va_start(lst, s);
	while (*s && length >= 0)
	{
		if (*s == '%')
		{
			if (ft_search(*(s + 1), "cspdiuxX%"))
				length = ft_read(*(s++ + 1), lst, length);
		}
		else
		{
			length++;
			if (ft_putchar(*s) == -1)
				length = -1;
		}
		s++;
	}
	va_end(lst);
	return (length);
}
