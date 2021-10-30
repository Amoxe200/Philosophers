# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaqari <aaqari@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 15:18:46 by aaqari            #+#    #+#              #
#    Updated: 2021/10/30 16:24:21 by aaqari           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = philosophers
CC = gcc
Src = main.c
Obj = ${Src:.c=.o}
FLAGS = -Wall -Wextra -Werror -pthread

all : ${Name}

${Name}: 
		@$(CC) -c $(Src) $(FLAGS) -o ${Name}

clean : 
		rm -rf $(Obj)

flclean : clean
		rm -rf $(Name)

re : flclean all