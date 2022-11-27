/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:42:41 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/27 22:46:23 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print_value(char c, va_list *values)
{
	if (c == 'p')
		return (ft_print_addr(va_arg(*values, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(*values, int)));
	if (c == 'x')
		return (ft_print_hexa(va_arg(*values, int)));
	if (c == 'X')
		return (ft_print_hexa_capslock(va_arg(*values, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(*values, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (ft_putstr(va_arg(*values, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(*values, int)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	size;
	int		error;
	va_list	values;

	if (!format)
		return (0);
	va_start(values, format);
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			error = ft_print_value(format[++i], &values);
			if (error != -1)
				size += error;
			else
				return (error);
		}
		else
		{
			error = write(1, format + i, 1);
			if (error != -1)
				size += error;
			else
				return (error);
		}
		i++;
	}
	va_end(values);
	return (size);
}
