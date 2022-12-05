/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:26:53 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/26 22:24:10 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_int(int nb)
{
	return (ft_putnbr(nb));
}

size_t	ft_print_unsigned(unsigned int nb)
{
	size_t	res;

	res = 0;
	if (nb >= 10)
		res += ft_print_unsigned(nb / 10);
	ft_putchar(nb % 10 + '0');
	res++;
	return (res);
}
