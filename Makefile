# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:15:44 by adrmarqu          #+#    #+#              #
#    Updated: 2024/02/12 18:58:41 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = include/ft_printf.h libft/libft.h
INCLUDEB = include/ft_printf_bonus.h

CC = gcc
CCFLAGS = -Wall -Wextra -Werror -Iinclude

AR = ar rcs
RM = rm -f

CLS = clear
SEE = ls

LIBFTDIR = ./libft
LIBFTA = libft.a

MAKECC = make
MAKECLEAN = make clean
MAKEFCLEAN = make fclean

SRC =	src/ft_num.c 					\
		src/ft_printf.c					\
		src/ft_putchar.c 				\
		src/ft_putnbr.c					\

OBJ = $(SRC:.c=.o)

BONUSSRC =	bonus/ft_flags_bonus.c		\
			bonus/ft_num_bonus.c		\
			bonus/ft_printf_bonus.c		\
			bonus/ft_putchar_bonus.c	\
			bonus/ft_putflags_bonus.c	\
			bonus/ft_putnbr_bonus.c		\
			bonus/init_bonus.c			\

BONUSOBJ = $(BONUSSRC:.c=.o)

all: $(NAME)

lib:
	@cd $(LIBFTDIR) && $(MAKECC)
	@cp $(LIBFTDIR)/$(LIBFTA) .
	@mv $(LIBFTA) $(NAME)

$(NAME): lib $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE) $(INCLUDEB) Makefile
	$(CC) $(CCFLAGS) -c -o $@ $<

bonus: lib $(BONUSOBJ)
	@$(AR) $(NAME) $(BONUSOBJ)

clean: 
	@$(RM) $(OBJ) $(BONUSOBJ)
	@cd $(LIBFTDIR) && $(MAKECLEAN)
	@echo "---> Deleted '.o' of libftprintf"

fclean: 
	@$(RM) $(NAME) $(LIBFTA) $(OBJ) $(BONUSOBJ)
	@echo "---> Deleted '.o' of libftprintf"
	@echo "---> Deleted libftprintf.a"
	@echo "---> Deleted libft.a in ft_printf"
	@cd $(LIBFTDIR) && $(MAKEFCLEAN)

re: fclean all

.PHONY: all clean fclean re
