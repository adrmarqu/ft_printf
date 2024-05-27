/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:58:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/02 12:55:02 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NUMBR "0123456789abcdef"

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(char const *s, ...);
int	ft_di(int n);
int	ft_u(unsigned int n);
int	ft_dir(unsigned long p);
int	ft_xx(unsigned int n, char x);

int	ft_putnbr(unsigned long n, unsigned long base, char x);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
