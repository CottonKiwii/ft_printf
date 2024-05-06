/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/05/06 15:02:50 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	ft_print_format(va_list arg, const char *format)
{
	int	bytes;
	int	temp;
	int	i;

	i = 0;
	bytes = 0;
	while (format[i] && format)
	{
		if (format[i] == '%')
		{
			temp = ft_eval(arg, format[i + 1]);
			i++;
		}
		else
			temp = write(STDOUT_FILENO, &format[i], 1);
		if (temp == -1)
			return (temp);
		bytes += temp;
		i++;
	}
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	i;
	size_t	bytes;
	int		temp;

	i = 0;
	bytes = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	temp = ft_print_format(arg, format);
	if (temp == -1)
		return (temp);
	bytes = temp;
	va_end(arg);
	return (bytes);
}
