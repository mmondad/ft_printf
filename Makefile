# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmondad <mmondad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:22:53 by mmondad           #+#    #+#              #
#    Updated: 2023/11/28 13:00:15 by mmondad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
SOURCES = putnbr_s_i.c putnbr_u_i.c ft_putstr.c ft_putchar.c put_hex.c ft_printf.c
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar -rcs  $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re