/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: korzecho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:11:56 by korzecho          #+#    #+#             */
/*   Updated: 2024/04/25 18:11:58 by korzecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list args)
{
	int	a;
	int	length;

	length = 0;
	a = va_arg(args, int);
	ft_putnbr_fd(a, 1);
	if (a < 0)
		length++;
	while (a / 10)
	{
		length++;
		a /= 10;
	}
	return (length + 1);
}
