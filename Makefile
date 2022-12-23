# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 03:18:02 by hel-ayac          #+#    #+#              #
#    Updated: 2021/12/13 03:18:06 by hel-ayac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a
MAIN= push_swap.c
SRCS= argsmanager.c group_handler.c handler.c make_groups.c make_sorting.c operation_a.c\
	operation_b.c operation_ab.c operation_handler.c sort.c tools.c tools2.c tools3.c
OBJ= $(SRCS:.c=.o)
INCLUDE= push_swap.h

FLG= -Wall -Wextra -Werror

all: push_swap

push_swap: $(MAIN) $(INCLUDE) $(NAME)
	gcc $(FLG) $(MAIN) -I $(INCLUDE) $(NAME) -o push_swap
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f push_swap


%.o: %.c
	gcc $(FLG) -c $< -I $(INCLUDE)

re: fclean all	
