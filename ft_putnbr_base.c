/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:07:25 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/25 11:01:11 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_verif_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;
	int	sign;
	size_t res;

	res = 0;
	sign = 1;
	base_length = ft_strlen(base);
	if (!ft_verif_base(base) || base_length < 2)
		return (0);
	if (nbr < 0)
	{
		ft_putchar('-');
		sign = -1;
	}
	if (nbr >= base_length || (-base_length) >= nbr)
		res += ft_putnbr_base(nbr / base_length * sign, base);
	write(1, &base[nbr % base_length * sign], 1);
	return (++res);
}
