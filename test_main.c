/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:07:50 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/27 15:09:34 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int main()
{
	int	a;
	int	b;
	char c = 'A';
    char s[] = "Hello";
    int d = 123;
    int i = -456;
    unsigned int u = 789;
    void *p = &d;
    unsigned int x = 0xABC;
    unsigned int X = 0xDEF;

	// Sin flags

	a = printf("Hola como estas?\n");
	b = ft_printf("Hola como estas?\n");
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");
	a = printf("Hola como\0 estas?\n");
	printf("\n");
	b = ft_printf("Hola como\0 estas?\n");
	printf("\n");
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");
	a = printf("Hola como%\0 estas?\n");
	printf("\n");
	b = ft_printf("Hola como%\0 estas?\n");
	printf("\n");
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");
	a = printf("Hola como%w estas?\n");
	b = ft_printf("Hola como%w estas?\n");
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");
	a = printf("Hola como%% estas?\n");
	b = ft_printf("Hola como%% estas?\n");
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");
	a = printf("%c %s %p %d %i %u %x %X\n", 'a', "Hola", NULL, 42, -42, 84, 42, 42);
	b = ft_printf("%c %s %p %d %i %u %x %X\n", 'a', "Hola", NULL, 42, -42, 84, 42, 42);
	printf("\n%d - %d\n", a, b);
	printf("\n------------------------------\n");

    return 0;
}
