/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:42:41 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/26 22:24:05 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print_value(char c, va_list values)
{
	if (c == 'p')
		return (ft_print_addr(va_arg(values, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_int(va_arg(values, int)));
	if (c == 'x')
		return (ft_print_hexa(va_arg(values, int)));
	if (c == 'X')
		return (ft_print_hexa_capslock(va_arg(values, int)));
	if (c == 'u')
		return (ft_print_unsigned(va_arg(values, unsigned int)));
	if (c == '%')
		return (write(1, "%", 1));
	if (c == 's')
		return (ft_putstr(va_arg(values, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(values, int)));
	return (0);
}

size_t	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	size;
	va_list	values;

	if (!format)
		return (0);
	va_start(values, format);
	size = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			size += ft_print_value(format[++i], values);
		else
		{
			write(1, format + i, 1);
			size++;
		}
		i++;
	}
	va_end(values);
	return (size);
}

// int main()
// {
// 	int a;

// 	a = '0';
// 	a = ft_printf("%s\n", NULL);
// 	printf("%d\n", a);
// 	a = printf("%s\n", NULL);
// 	printf("%d\n", a);
// 	return (0);
// }
