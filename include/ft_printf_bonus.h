/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:41:21 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/27 15:12:57 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define NUMBR "0123456789abcdef"

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_flag
{
	int		length;
	int		error;
	int		space;
	int		minus;
	int		alter;
	int		zero;
	int		width;
	int		aim;
	char	sign;
	char	type;
}	t_flag;

int		ft_printf(char const *s, ...);
void	ft_di(int n, t_flag *flag);
void	ft_u(unsigned int n, t_flag *flag);
void	ft_dir(unsigned long p, t_flag *flag);
void	ft_xx(unsigned int n, t_flag *flag);

void	ft_putnbr(unsigned long n, unsigned long base, t_flag *flag);
void	ft_putchar(char c, t_flag *flag);
void	ft_putchar_flag(char c, t_flag *flag);
void	ft_putstr(char *s, t_flag *flag);
void	ft_putstr_flag(char *s, t_flag *flag);

t_flag	init_struct(void);
void	reset_flags(t_flag *flag);
void	get_flags(char **s, t_flag *flag);

void	ft_add_width(t_flag *flag, int len, char c);
char	*ft_put_flags(char *s, t_flag *flag);

#endif
