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
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*arg;
	va_list	args;

	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			arg = va_arg(args, char *);
			check_arg(format[i + 1], arg);
		}
		else if (format[i])
			check_slesh(format[i + 1]);
		else
			write(1, &format, 1);
	}
}

char	*check_arg(char c, char *arg)
{
	if (c == 'c')
		
}

void check_slesh(char c)
{
    
}