# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 17:04:44 by jwolfram          #+#    #+#              #
#    Updated: 2024/04/26 15:42:15 by jwolfram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

### Compilation ###

CC := cc

CFLAGS := -Wall -Wextra -Werror

INCLUDE := -I./includes/

AR := ar -rcs

RM := rm -rf

### Sources ###

SRC_DIR := src/

SRCS_FILES := ft_printf.c \
			  ft_print_char.c \
			  ft_print_str.c \
			  ft_print_nbr.c \
			  ft_print_ptr.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c

SRCS = ${addprefix ${SRC_DIR}, ${SRCS_FILES}}

OBJS := ${SRCS:.c=.o}

### Library/Header ###

HEADER := ft_printf.h

LIBFT_DIR := ./libft/

LIBFT := libft.a

LIBFT_AR := ./libft/libft.a

### Commands ###

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
