/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:31:23 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/26 15:31:50 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long hex, int format)
{
	char	*base;
	int		bytes;
	int		temp;

	base = "0123456789abcdef";
	if (!hex)
		return (write(STDOUT_FILENO, "(nil)", 5));
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (hex < 16)
	{
		temp = ft_print_char(base[hex]);
		return (temp);
	}
	temp = ft_print_hex(hex / 16, format);
	if (temp == -1)
		return (temp);
	bytes = temp;
	temp = ft_print_hex(hex % 16, format);
	if (temp == -1)
		return (temp);
	bytes += temp;
	return (bytes);
}
