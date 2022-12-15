# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 11:57:23 by fle-tolg          #+#    #+#              #
#    Updated: 2022/10/26 12:56:58 by fle-tolg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wextra -Wall -Werror

CC = gcc

AR = ar rc

RM = rm -f

OBJ = $(SRC:.c=.o)

SRC = sources/ft_putcharf.c\
	sources/ft_putnbrf_hexa_min.c\
	sources/ft_putnbrf_hexa_maj.c\
	sources/ft_putnbrf_uint.c\
	sources/ft_putper.c\
	sources/ft_putstrf.c\
	sources/ft_putnbrf.c\
	sources/ft_putaddr.c\
	ft_printf.c

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : ${OBJ}
	$(AR) $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY :
	all clean fclean re
