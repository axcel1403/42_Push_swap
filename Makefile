# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 19:59:56 by jmiranda          #+#    #+#              #
#    Updated: 2023/05/01 19:56:16 by jmiranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH   = src:src_bonus

NAME    = push_swap

NAME_B  = checker

SRCS    = assign.c clear_and_error.c convert_and_sorted.c main.c moves.c \
          decisions_and_operations.c moves_and_utils.c push.c rev_rotate.c \
		  rotate.c swap.c \

SRCS_B  = checker_bonus.c clear_and_error_bonus.c convert_and_sorted_bonus.c \
		  main_bonus.c push_bonus.c rev_rotate_bonus.c rotate_bonus.c \
		  swap_bonus.c  

LIBFT   = libft/libft.a

OBJS    = ${SRCS:.c=.o}

OBJS_B  = ${SRCS_B:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror -Iinc -Ilibft

all     : ${NAME}

${NAME} : ${LIBFT} ${OBJS}
				@$(CC) ${LIBFT} ${OBJS} -o ${NAME}
				@echo Push_Swap Is Complete!
				
${LIBFT}:
				@$(MAKE) -C libft
				@$(MAKE) -C libft bonus

bonus   : ${LIBFT} ${OBJS_B} 
				@$(CC) ${LIBFT} ${OBJS_B} -o ${NAME_B}
				@echo Checker Is Complete!
				
%.o     : %.c
				@echo -n .
				@$(CC) $(CFLAGS) -c $< -o $@

clean   :
				rm -f *.o libft/*.o

fclean  : clean
				rm -f ${NAME} ${NAME_B} ${LIBFT}

re      : fclean all

.PHONY  : all bonus clean fclean re
