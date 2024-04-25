/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/25 18:08:49 by jwolfram         ###   ########.fr       */
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

int	print_str(char *str)
{
	size_t	i;
	int	bytes;

	i = 0;
	bytes = 0;
	if (!str)
		return (write(STDOUT_FILENO, "(nil)", 5));
	while (str[i])
	{
		bytes += write(STDOUT_FILENO, &str[i], 1);
		i++;
	}
	return (bytes);
}

int	print_ptr(void *ptr)
{
	int	bytes;
	int	temp;

	if (!ptr)
		return (write(STDOUT_FILENO, "(nil)", 5));
	temp = print_str("0x");
	if (temp == -1)
		return (temp);
}

// ACTUAL FT_PRINTF.C FILE

static int	ft_eval(va_list arg, int format)
{
	if (format == 'c')
		return (print_char(va_arg(arg, int)));
	else if (format == 's')
		return (print_str(va_arg(arg, char *)));
	else if (format == 'p')
		return (print_ptr(va_arg(arg, void *)));
/*	else if (format == 'd' || format == 'i')
		return (print_nbr(va_arg(arg, int)));
	else if (format == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (print_hex(va_arg(arg, unsigned int)));
*/
	else if (format == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	size_t	len;
	size_t	i;

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
