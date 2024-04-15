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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "test.c"

int print_char(va_list args)
{
	char a;
	a = va_arg(args, int);
	ft_putchar_fd(a,1);
	return 0;
}
int print_string(va_list args)
{
	char *a;
	a = va_arg(args, char *);
	ft_putstr_fd(a, 1);
	return 0;
}
int print_int(va_list args)
{
	int a;
	a = va_arg(args, int);
	ft_putnbr_fd(a, 1);
	return 0;
}
int print_hex_long(va_list args)
{
	unsigned long long a;
	a = va_arg(args, unsigned long long);
	hex_length(a);
	return 0;
}
int print_unsigned_int(va_list args)
{
	unsigned int	a;
	a = va_arg(args, unsigned int);
	ft_putnbr_fd((int)a, 1);
	return 0;
}
int	check_arg(char c, va_list args)
{
	if (c == 'c')
		print_char(args);
	else if (c == 's' || c == 'x' || c == 'X')	
		print_string(args);
	else if (c == 'd' || c == 'i')
		print_int(args);
	else if (c == 'u')
		print_unsigned_int(args);
	//else if (c == 'p')
		//
	else if (c == '?')
		ft_putchar_fd('?', 1);
	return 0;
}
int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			check_arg(format[i + 1], args);
			i++;
		}
		// else if (format[i])
		// 	check_slesh(format[i + 1]);
		else
			ft_putchar_fd((char)format[i], 1);
	}
	va_end(args);
	return 0;
}
int main ()
{
	printf("test: \n");
	ft_printf(" %d ", 0);
	printf("\nend\n");
	return 0;
}
