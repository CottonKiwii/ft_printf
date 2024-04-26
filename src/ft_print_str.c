/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:30:19 by jwolfram          #+#    #+#             */
/*   Updated: 2024/04/26 17:14:24 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	size_t	i;
	int		bytes;
	int		len;

	i = 0;
	bytes = 0;
	if (!str)
	{
		bytes = write(STDOUT_FILENO, "(null)", 6);
		return (bytes);
	}
	len = ft_strlen(str);
	bytes += write(STDOUT_FILENO, str, len);
	return (bytes);
}
