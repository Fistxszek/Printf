/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:49:59 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/23 17:50:01 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_char(va_list args);
int	print_int(va_list args);
int	print_string(va_list args);
int	print_unsigned_int(va_list args);
int	print_pointer(va_list args);
int	hex_printer(unsigned long long nbr, char format);
int	print_hex_long(va_list args, char format);
#endif