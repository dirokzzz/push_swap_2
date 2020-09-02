#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcolossu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 20:49:09 by bcolossu          #+#    #+#              #
#    Updated: 2019/11/21 19:42:55 by rczarfun         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = checker.h
SRC =	main.c\
		operations1.c\
		pars_check_args.c\
		stack_op.c\

OBJ = $(SRC:c=o)


all: $(NAME)

$(NAME): $(OBJ)
	@make -C .././libft
	$(CC) $(FLAGS) -I$(INC) ../libft/libft.a $(OBJ) -o $(NAME)
	

%.o : %.c $(INC)
	$(CC) $(FLAGS) -I$(INC) -o $@ -c $<

clean:
	@$(MAKE) -C ../libft/ clean
	@/bin/rm -f *.o

fclean: clean
	@$(MAKE) -C ../libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
