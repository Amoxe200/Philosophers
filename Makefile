# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 15:18:46 by aaqari            #+#    #+#              #
#    Updated: 2021/11/03 14:49:50 by aaqari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c philo_utils.c thread.c
NAME = philo

all: $(NAME)

$(NAME): 
	gcc -Wall -Werror -Wextra -o $(NAME) -pthread $(SRC)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all