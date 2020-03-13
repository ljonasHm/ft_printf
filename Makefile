# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrayne <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 17:20:34 by rrayne            #+#    #+#              #
#    Updated: 2020/03/10 14:48:54 by ljonas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c

HEADER = ft_printf.h

OBJ	= $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -c

LIBFT = libft/libft.a

LIB_DIR = libft

INC_DIR = . libft

all: $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAG) -c $<

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	ar rc $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
