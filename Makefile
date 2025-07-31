# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shintarokohtake <shintarokohtake@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 21:20:28 by shintarokoh       #+#    #+#              #
#    Updated: 2025/07/31 21:26:31 by shintarokoh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := step
SRCS := step.c

CC := cc
CFLAGS :=	#	-Wall -Wextra -Werror

all : $(NAME)

step : step.c
# 	make -C ../libft
# 	make -C ../libft clean
	$(CC) -o $@ $(CFLAGS) $^ -L../libft -lft -L../gnl -lgnl -L../ft_printf -lftprintf

linker :
	make -C ./libft re
	make -C ./ft_printf re
	make -C ./libft clean
	make -C ./ft_printf clean

clean :
	rm -f *.o

fclean :
	make clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
