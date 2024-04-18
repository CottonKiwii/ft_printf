# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:04:44 by jwolfram          #+#    #+#              #
#    Updated: 2024/04/18 17:29:29 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc 

CFLAGS := -Wall -Wextra -Werror

SRCS := ft_printf.c

OBJS := ${SRCS:.c=.o}

LIBC := ar -rcs

RM := rm -rf

all: ${NAME}

${NAME} : ${OBJS}
	${LIBC} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} $< -I. -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
