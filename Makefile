# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:04:44 by jwolfram          #+#    #+#              #
#    Updated: 2024/04/18 19:08:04 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

CC := cc 

CFLAGS := -Wall -Wextra -Werror

SRCS := src/ft_printf.c

OBJS := ${SRCS:.c=.o}

AR := ar -rcs

LIBFT := ${MAKE} -C libft

HEADER := ft_printf.h

RM := rm -rf

all: ${LIBFT} ${NAME}

${NAME} : ${OBJS} ${HEADER}
	${AR} ${NAME} ${OBJS}

%.o: %.c
	${CC} ${CFLAGS} $< -I. -o $@

clean:
	${LIBFT} $@
	${RM} ${OBJS}

fclean: clean
	${LIBFT} $@
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
