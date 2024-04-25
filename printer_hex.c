/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:35:09 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/23 15:35:10 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex_len(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits++;
		n /= 16;
	}
	return (digits);
}

static int	print_hex(unsigned long long nbr, char format)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		print_hex(nbr / 16, format);
	if (format == 'x')
		write (1, &lower_digits[nbr % 16], 1);
	else if (format == 'X')
		write (1, &upper_digits[nbr % 16], 1);
	return (1);
}

int	hex_printer(unsigned long long nbr, char format)
{
	print_hex(nbr, format);
	return (count_hex_len(nbr));
}

int	print_hex_long(va_list args, char format)
{
	unsigned long long	a;

	a = va_arg(args, unsigned long long);
	if (a == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (hex_printer(a, format));
}
