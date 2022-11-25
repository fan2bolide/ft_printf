/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:25:14 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/25 11:58:38 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_addr(void *ptr)
{
	write(1, "0x", 2);
	return (ft_putnbr_base_unsigned((size_t)ptr, "0123456789abcdef") + 2);
}

size_t	ft_print_hexa(int nb)
{
	return (ft_putnbr_base_unsigned((unsigned int)nb, "0123456789abcdef"));
}

size_t	ft_print_HEXA(int nb)
{
	return (ft_putnbr_base_unsigned((unsigned int)nb, "0123456789ABCDEF"));
}