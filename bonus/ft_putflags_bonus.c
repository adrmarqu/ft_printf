/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:15:13 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/27 14:35:42 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_add_width(t_flag *flag, int len, char c)
{
	int	length;

	length = flag->width - len;
	if (length < 0)
		length = 0;
	while (length > 0)
	{
		ft_putchar(c, flag);
		length--;
	}
}

static char	*ft_add_aim_str(char *s, t_flag *flag)
{
	char	*r;
	int		i;

	r = (char *)ft_calloc((size_t)flag->aim + 1, sizeof(char));
	if (!r)
	{
		flag->error = 1;
		return (NULL);
	}
	i = 0;
	while (i < flag->aim)
	{
		r[i] = *s;
		i++;
		s++;
	}
	s = r;
	free(r);
	return (s);
}

static void	*ft_add_aim_num2(char *s, char *r, t_flag *flag)
{
	int	length;
	int	i;

	i = 0;
	length = flag->aim - (int)ft_strlen(s);
	while (i < length)
	{
		r[i] = '0';
		i++;
	}
	length = (int)ft_strlen(s);
	while (length > 0)
	{
		r[i] = *s;
		i++;
		s++;
		length--;
	}
	return (r);
}

static char	*ft_add_aim_num(char *s, t_flag *flag)
{
	char	*r;
	int		length;

	if (flag->aim > (int)ft_strlen(s))
	{
		length = (int)ft_strlen(s) + flag->aim;
		r = (char *)ft_calloc(length, sizeof(char));
		if (!r)
		{
			flag->error = 1;
			return (NULL);
		}
		r = ft_add_aim_num2(s, r, flag);
		s = r;
		free(r);
	}
	return (s);
}

char	*ft_put_flags(char *s, t_flag *flag)
{
	if (flag->aim != -1)
	{
		if (flag->type == 's')
			s = ft_add_aim_str(s, flag);
		else
			s = ft_add_aim_num(s, flag);
	}
	if ((flag->sign == '+' || flag->sign == '-' || flag->space)
		&& flag->type != 's')
		flag->width--;
	if (!flag->minus && !flag->zero)
		ft_add_width(flag, (int)ft_strlen(s), ' ');
	if ((flag->sign == '+' || flag->sign == '-') && flag->type != 's')
		ft_putchar(flag->sign, flag);
	if (flag->space && flag->type != 's')
		ft_putchar(' ', flag);
	if (flag->type == 'p' || (flag->alter && flag->type == 'x'))
		ft_putstr("0x", flag);
	if (flag->alter && flag->type == 'X')
		ft_putstr("0X", flag);
	if (flag->zero)
		ft_add_width(flag, (int)ft_strlen(s), '0');
	return (s);
}
