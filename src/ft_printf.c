/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/26 15:38:51 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "unistd.h"

static int	ft_eval(va_list arg, int format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(arg, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(arg, unsigned int)));
	else if (format == 'X' || format == 'x')
		return (ft_print_hex(va_arg(arg, unsigned long), format));
	else if (format == '%')
		return (ft_print_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	size_t	bytes;
	size_t	i;

	i = 0;
	bytes = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			bytes += ft_eval(arg, format[i + 1]);
			if (bytes == -1)
				return (bytes);
			i++;
		}
		else
			bytes += write(STDOUT_FILENO, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (bytes);
}
