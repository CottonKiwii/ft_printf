# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:04:44 by jwolfram          #+#    #+#              #
#    Updated: 2024/04/23 18:27:26 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

# Compilation

CC := cc

CFLAGS := -Wall -Wextra -Werror

INCLUDE := -I./includes/

AR := ar -rcs

RM := rm -rf

# Sources

SRC_DIR := src/

SRCS := ft_printf.c

OBJS := ${SRCS:.c=.o}

HEADER := ft_printf.h

LIBFT_DIR := ./libft/

LIBFT := libft.a

LIBFT_AR := ./libft/libft.a

all: ${NAME}

${NAME} : ${OBJS} ${LIBFT_AR}
	cp ${LIBFT_AR} ${NAME}
	${AR} ${NAME} ${OBJS}

${LIBFT_AR}:
	${MAKE} -C ${LIBFT_DIR}

%.o: %.c
	${CC} ${CFLAGS} $< ${INCLUDE} -c -o $@

clean:
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${OBJS}

fclean: clean
	${MAKE} $@ -C ${LIBFT_DIR}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
