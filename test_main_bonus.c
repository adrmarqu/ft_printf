/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:07:42 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/05/27 15:15:00 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf_bonus.h"

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

	// Bonus
	
	a = 0;
	b = 0;
	
	printf("\n--------------------------\n\n");

	printf("%%c\n\n");
    
	a += printf("'%05c'\n",c);
	a += printf("'%-5c'\n",c);
	a += printf("'%+5c'\n",c);
	a += printf("'% c'\n",c);
	a += printf("'%#5c'\n",c);
	a += printf("'%5.c'\n",c);
	a += printf("'%5.0c'\n",c);
	a += printf("'%05.7c'\n",c);

	printf("\n");
	
	b += ft_printf("'%05c'\n",c);
 	b += ft_printf("'%-5c'\n",c);
	b += ft_printf("'%+5c'\n",c);
	b += ft_printf("'% c'\n",c);
	b += ft_printf("'%#5c'\n",c);
	b += ft_printf("'%5.c'\n",c);
	b += ft_printf("'%5.0c'\n",c);
	b += ft_printf("'%05.7c'\n",c);

	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%s\n\n");
    
	a += printf("'%010s'\n",s);
	a += printf("'%-10s'\n",s);
	a += printf("'%+10s'\n",s);
	a += printf("'% s'\n",s);
	a += printf("'%#10s'\n",s);
	a += printf("'%10.s'\n",s);
	a += printf("'%10.0s'\n",s);
	a += printf("'%10.2s'\n",s);

	printf("\n");
    
	b += ft_printf("'%010s'\n",s);
	b += ft_printf("'%-10s'\n",s);
	b += ft_printf("'%+10s'\n",s);
	b += ft_printf("'% s'\n",s);
	b += ft_printf("'%#10s'\n",s);
	b += ft_printf("'%10.s'\n",s);
	b += ft_printf("'%10.0s'\n",s);
	b += ft_printf("'%10.2s'\n",s);

	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%p\n\n");
    
	a += printf("'%020p'\n",p);
	a += printf("'%-20p'\n",p);
	a += printf("'%+20p'\n",p);
	a += printf("'% p'\n",p);
	a += printf("'%#20p'\n",p);
	a += printf("'%20.p'\n",p);
	a += printf("'%20.0p'\n",p);
	a += printf("'%20.2p'\n",p);

	printf("\n");
	
	b += ft_printf("'%020p'\n",p);
	b += ft_printf("'%-20p'\n",p);
	b += ft_printf("'%+20p'\n",p);
	b += ft_printf("'% p'\n",p);
	b += ft_printf("'%#20p'\n",p);
	b += ft_printf("'%20.p'\n",p);
	b += ft_printf("'%20.0p'\n",p);
	b += ft_printf("'%20.2p'\n",p);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%d\n\n");
    
	a += printf("'%010d'\n",d);
	a += printf("'%-10d'\n",d);
	a += printf("'%+10d'\n",d);
	a += printf("'% d'\n",d);
	a += printf("'%#10d'\n",d);
	a += printf("'%10.d'\n",d);
	a += printf("'%10.0d'\n",d);
	a += printf("'%010.5d'\n",d);

	printf("\n");
	
	b += ft_printf("'%010d'\n",d);
	b += ft_printf("'%-10d'\n",d);
	b += ft_printf("'%+10d'\n",d);
	b += ft_printf("'% d'\n",d);
	b += ft_printf("'%#10d'\n",d);
	b += ft_printf("'%10.d'\n",d);
	b += ft_printf("'%10.0d'\n",d);
	b += ft_printf("'%010.5d'\n",d);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%i\n\n");
    
	a += printf("'%010i'\n",i);
	a += printf("'%-10i'\n",i);
	a += printf("'%+10i'\n",i);
	a += printf("'% i'\n",i);
	a += printf("'%#10i'\n",i);
	a += printf("'%10.i'\n",i);
	a += printf("'%10.0i'\n",i);
	a += printf("'%010.5i'\n",i);

	printf("\n");
	
	b += ft_printf("'%010i'\n",i);
	b += ft_printf("'%-10i'\n",i);
	b += ft_printf("'%+10i'\n",i);
	b += ft_printf("'% i'\n",i);
	b += ft_printf("'%#10i'\n",i);
	b += ft_printf("'%10.i'\n",i);
	b += ft_printf("'%10.0i'\n",i);
	b += ft_printf("'%010.5i'\n",i);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");

	printf("%%u\n\n");
    
	a += printf("'%010u'\n",u);
	a += printf("'%-10u'\n",u);
	a += printf("'%+10u'\n",u);
	a += printf("'% u'\n",u);
	a += printf("'%#10u'\n",u);
	a += printf("'%10.u'\n",u);
	a += printf("'%10.0u'\n",u);
	a += printf("'%010.5u'\n",u);
	
	printf("\n");
	
	b += ft_printf("'%010u'\n",u);
	b += ft_printf("'%-10u'\n",u);
	b += ft_printf("'%+10u'\n",u);
	b += ft_printf("'% u'\n",u);
	b += ft_printf("'%#10u'\n",u);
	b += ft_printf("'%10.u'\n",u);
	b += ft_printf("'%10.0u'\n",u);
	b += ft_printf("'%010.5u'\n",u);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%x\n\n");
    
	a += printf("'%010x'\n",x);
	a += printf("'%-10x'\n",x);
	a += printf("'%+10x'\n",x);
	a += printf("'% x'\n",x);
	a += printf("'%#10x'\n",x);
	a += printf("'%10.x'\n",x);
	a += printf("'%10.0x'\n",x);
	a += printf("'%010.5x'\n",x);

	printf("\n");
	
	b += ft_printf("'%010x'\n",x);
	b += ft_printf("'%-10x'\n",x);
	b += ft_printf("'%+10x'\n",x);
	b += ft_printf("'% x'\n",x);
	b += ft_printf("'%#10x'\n",x);
	b += ft_printf("'%10.x'\n",x);
	b += ft_printf("'%10.0x'\n",x);
	b += ft_printf("'%010.5x'\n",x);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%X\n\n");
    
	a += printf("'%010X'\n",X);
	a += printf("'%-10X'\n",X);
	a += printf("'%+10X'\n",X);
	a += printf("'% X'\n",X);
	a += printf("'%#10X'\n",X);
	a += printf("'%10.X'\n",X);
	a += printf("'%10.0X'\n",X);
	a += printf("'%010.5X'\n",X);

	printf("\n");
	
	b += ft_printf("'%010X'\n",X);
	b += ft_printf("'%-10X'\n",X);
	b += ft_printf("'%+10X'\n",X);
	b += ft_printf("'% X'\n",X);
	b += ft_printf("'%#10X'\n",X);
	b += ft_printf("'%10.X'\n",X);
	b += ft_printf("'%10.0X'\n",X);
	b += ft_printf("'%010.5X'\n",X);
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");
	
	printf("%%%%\n\n");
    
	a += printf("'%010%'\n");
	a += printf("'%-10%'\n");
	a += printf("'%+10%'\n");
	a += printf("'% %'\n");
	a += printf("'%#10%'\n");
	a += printf("'%10.%'\n");
	a += printf("'%10.0%'\n");
	a += printf("'%010.5%'\n");
	
	printf("\n");
	
	b += ft_printf("'%010%'\n");
	b += ft_printf("'%-10%'\n");
	b += ft_printf("'%+10%'\n");
	b += ft_printf("'% %'\n");
	b += ft_printf("'%#10%'\n");
	b += ft_printf("'%10.%'\n");
	b += ft_printf("'%10.0%'\n");
	b += ft_printf("'%010.5%'\n");
	
	printf("\n%d-%d\n", a, b);
	a = 0;
	b = 0;

	printf("\n--------------------------\n\n");

	printf("Combinaciones\n\n");
	
	a += printf("'%#010x'\n",x);
	a += printf("'%#010X'\n",X);
	a += printf("'%#10x'\n", 0);
	a += printf("'%#10X'\n", 0);
	a += printf("'%010p'\n", NULL);
	a += printf("'%010s'\n", NULL);
	
	printf("\n");
	
	b += ft_printf("'%#010x'\n",x);
	b += ft_printf("'%#010X'\n",X);
	b += ft_printf("'%#10x'\n", 0);
	b += ft_printf("'%#10X'\n", 0);
	b += ft_printf("'%010p'\n", NULL);
	b += ft_printf("'%010s'\n", NULL);

	printf("\n%d-%d\n", a, b);
	
	printf("\n--------------------------\n\n");

    return 0;
}
