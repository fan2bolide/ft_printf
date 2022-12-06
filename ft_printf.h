/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:43:00 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/07 00:16:23 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_addr(void *ptr);
int	ft_print_int(int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_hexa(int nb);
int	ft_print_hexa_capslock(int nb);
int	ft_putnbr_base(int nb, char *base);
int	ft_putnbr_base_unsigned(size_t nb, char *base);

#endif