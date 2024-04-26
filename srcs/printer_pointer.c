/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:08:10 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/25 18:08:11 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_ptr_len(unsigned long long n)
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

static int	print_ptr(unsigned long long nbr, char format)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		print_ptr(nbr / 16, format);
	if (format == 'x')
		write (1, &lower_digits[nbr % 16], 1);
	else if (format == 'X')
		write (1, &upper_digits[nbr % 16], 1);
	return (1);
}

static int	ptr_printer(unsigned long long nbr, char format)
{
	print_ptr(nbr, format);
	return (count_ptr_len(nbr));
}

int	print_pointer(va_list args)
{
	unsigned long long	a;

	a = (unsigned long long)va_arg(args, void *);
	if (a == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ptr_printer(a, 'x') + 2);
}
