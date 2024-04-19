/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/19 12:57:50 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_eval(va_list arg, const char *format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(arg, char *)));
	else if (format == 'd')
		return (ft_putdec(va_arg(arg, int)));
	else if (format == 'i')
		return (ft_putint(va_arg(arg, int)));
	else if (format == 'u')
		return (ft_putundec(va_arg(arg, unsigned int)));
	else if (format == 'x')
		return (ft_puthexlow(va_arg(arg, unsigned int)));
	else if (format == 'X')
		return (ft_puthexup(va_arg(arg, unsigned int)));
	else if (format == '%')
		write(1, '%', 1);
}

int	ft_printf(const char *format, ...)
{
	va_list arg;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
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
	ft_printf("world");
	return (0);
}
