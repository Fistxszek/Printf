/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:25:14 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/24 19:25:15 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_unsigned_len(unsigned int n)
{
	size_t digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int	print_unsigned(unsigned int nbr)
{
	static char	unsigned_digits[] = "0123456789";

	if (nbr >= 10)
		print_unsigned(nbr / 10);
	write (1, &unsigned_digits[nbr % 10], 1);
	return (1);
}

int	unsigned_printer(unsigned int nbr)
{
	print_unsigned(nbr);
	return (count_unsigned_len(nbr));
}
