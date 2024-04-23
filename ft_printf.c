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

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <stdarg.h>
// #include "hex_printer.c"
// #include "Work_Libft/ft_putchar_fd.c"
// #include "Work_Libft/ft_putstr_fd.c"
// #include "Work_Libft/ft_putnbr_fd.c"
// #include "Work_Libft/ft_strlen.c"
#include "ft_printf.h"

int print_char(va_list args)
{
	char a;
	a = va_arg(args, int);
	ft_putchar_fd(a,1);
	return 1;
}
int print_string(va_list args)
{
	char *a;
	a = va_arg(args, char *);
	ft_putstr_fd(a, 1);
	return (ft_strlen(a));
}
int print_int(va_list args)
{
	int a;
	int	length;

	length = 0;
	a = va_arg(args, int);
	ft_putnbr_fd(a, 1);
	while (a /= 10)
		length++;
	return (length + 1);
}
int print_hex_long(va_list args, char format)
{
	unsigned long long a;
	a = va_arg(args, unsigned long long);
	return (put_hex(a, format));
}
int print_unsigned_int(va_list args)
{
	unsigned int	a;
	int				length;

	length = 0;
	a = va_arg(args, unsigned int);
	ft_putnbr_fd((int)a, 1);
	while (a /= 10)
		length++;
	return (length + 1);
}
int	check_arg(char c, va_list args)
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
	//else if (c == 'p')
		//
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
// int main ()
// {
// 	printf("test: \n");
// 	int i = ft_printf("%c",'a');
// 	printf("\nlen: %d -- end\n", i);
// 	return 0;
// }
