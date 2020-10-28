# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 23:25:34 by mel-haya          #+#    #+#              #
#    Updated: 2019/11/22 01:41:20 by mel-haya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_uitoa.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memset.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_toupper.c print_functions.c ft_atoi.c dec_to_hex.c flags.c
O = $(SRC:.c=.o)
B = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): 
	gcc $(SRC) -c $(FLAGS)
	ar rc $(NAME) $(O)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re:	fclean all
