# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 11:33:35 by dmarijan          #+#    #+#              #
#    Updated: 2024/04/11 15:18:35 by dmarijan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c find_utils.c manage_errors.c node_utils.c push.c rotate.c \
	  rrotate.c set_utils.c swap.c utils.c

OBJ = $(SRC:.c=.o)

COMPILE = gcc -Wall -Werror -Wextra -g

REMOVE = rm -f

BONUS = checker

BONUS_SRC = checker.c push.c rotate.c rrotate.c swap.c manage_errors.c \
			utils.c find_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(NAME): Makefile push_swap.h $(OBJ)
	make all -C libft
	@$(COMPILE) $(SRC) libft/libftprintf.a -o $(NAME)

$(BONUS): Makefile push_swap.h $(BONUS_OBJ)
	@$(COMPILE) $(BONUS_SRC) libft/libftprintf.a -o $(BONUS)

clean:
	make clean -C libft
	$(REMOVE) $(OBJ)
	$(REMOVE) $(BONUS_OBJ)

fclean: clean
	make fclean -C libft
	$(REMOVE) $(NAME)
	$(REMOVE) $(BONUS)
	rm -rf Push_Swap.dSYM
	rm -rf checker.dSYM

re: fclean all

.PHONY = all clean fclean re bonus
