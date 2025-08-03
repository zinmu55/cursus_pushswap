# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohtake <skohtake@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 21:20:28 by shintarokoh       #+#    #+#              #
#    Updated: 2025/08/03 21:19:40 by skohtake         ###   ########.fr        #
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
	$(CC) -o $@ $(CFLAGS) $^ -L./ft_printf -lftprintf
# 	$(CC) -o $@ $(CFLAGS) $^ -L./ft_printf -lftprintf -L./libft -lft 

linker :
	make -C ./ft_printf re
	make -C ./ft_printf clean
# 	make -C ./libft re
# 	make -C ./libft clean


clean :
	rm -f *.o

fclean :
	make clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
