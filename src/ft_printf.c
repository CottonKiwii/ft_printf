/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:21:25 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/19 12:09:21 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
//	va_list arg;
	int		len;
	int		i;

	i = 0;
	len = 0;
//	va_start(arg, format);
	while (format[i])
	{
//		if (format[i] == '%')
//		{}
//		else
		len += write(1, &format[i], 1);
		i++;
	}
//	va_end(arg);
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
