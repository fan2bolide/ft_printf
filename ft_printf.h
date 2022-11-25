/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:43:00 by bajeanno          #+#    #+#             */
/*   Updated: 2022/11/25 11:00:27 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

size_t	ft_printf(const char *format, ...);
size_t	ft_print_char(char c);
size_t	ft_print_string(char *str);
size_t 	ft_print_addr(void *ptr);
size_t	ft_print_int(int nb);
size_t	ft_print_unsigned(unsigned int nb);
size_t	ft_print_hexa(int nb);
size_t	ft_print_HEXA(int nb);

size_t	ft_putnbr_base(int nb, char *base);
size_t	ft_putnbr_base_unsigned(size_t nb, char *base);

#endif