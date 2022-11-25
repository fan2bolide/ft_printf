/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:42:41 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/25 13:16:47 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print_value(char c, va_list values)
{
	if (c == 'p')
		return (ft_print_addr(va_arg(values, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(values, int)) - 1);
	if (c == 'x')
		return (ft_print_hexa(va_arg(values, int)) - 1);
	if (c == 'X')
		return (ft_print_HEXA(va_arg(values, int)) - 1);
	if (c == 'u')
		return (ft_print_unsigned(va_arg(values, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (ft_putstr(va_arg(values, char *)));
	return 0;
}

size_t	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	size;
	va_list values;

	va_start(values, format);
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			size += ft_print_value(format[++i], values);
		else
			write(1, format + i, 1);
		i++;
		size++;
	}
	return (size - 1);
}

// int main()
// {
// 	int a;

// 	a = -42141342;
// 	a = ft_printf("%p %d %x %X\n",&a, a, a, a);
// 	printf("%d\n", a);
// 	a = -42141342;
// 	a = printf("%p %d %x %X\n",&a, a, a, a);
// 	printf("%d\n", a);
// 	return (0);
// }
