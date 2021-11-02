# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 15:18:46 by aaqari            #+#    #+#              #
#    Updated: 2021/11/02 19:26:46 by aaqari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c philo_utils.c thread.c
NAME = philosophers

all: $(NAME)

$(NAME): 
	gcc -Wall -Werror -Wextra -o philosophers -pthread $(SRC)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all