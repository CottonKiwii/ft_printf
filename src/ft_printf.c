/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/25 14:28:52 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

int	print_char(char c)
{
	int	bytes;

	bytes = write(STDOUT_FILENO, &c, 1);
	return (bytes);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_ptr(char *ptr)
{
	
}

static int	ft_eval(va_list arg, int format)
{
	if (format == 'c')
		return (print_char(va_arg(arg, int)));
	else if (format == 's')
		return (print_str(va_arg(arg, char *)));
	else if (format == 'p')
		return (print_ptr(va_arg(arg, char *)));
	else if (format == 'd')
		return (print_nbr(va_arg(arg, int)));
	else if (format == 'i')
		return (print_int(va_arg(arg, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (print_hex(va_arg(arg, unsigned int)));
	else if (format == '%')
		write(1, "%", 1);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	size_t	len;
	size_t	i;
	int		bytes;

	i = 0;
	len = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_eval(arg, format[i + 1]);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%s\n", argv[1]);
	ft_printf("%s", argv[1]);
	return (0);
}
