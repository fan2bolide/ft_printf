/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:42:41 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/24 17:57:38 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			size += ft_print_value(format[++i]);
		i++;
	}
	return (size);
}
