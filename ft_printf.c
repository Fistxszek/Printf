/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:13:51 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/06 18:13:53 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	check_arg(char c, va_list args)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'c')
		printed_chars += print_char(args);
	else if (c == 's')
		printed_chars += print_string(args);
	else if (c == 'x' || c == 'X')
		printed_chars += print_hex_long(args, c);
	else if (c == 'd' || c == 'i')
		printed_chars += print_int(args);
	else if (c == 'u')
		printed_chars += print_unsigned_int(args);
	else if (c == 'p')
		printed_chars += print_pointer(args);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		printed_chars++;
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed;
	va_list	args;

	printed = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			printed += check_arg(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd((char)format[i], 1);
			printed++;
		}
	}
	va_end(args);
	return (printed);
}
