/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:58:49 by sebasari          #+#    #+#             */
/*   Updated: 2023/11/24 11:15:51 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *str, size_t i, va_list args)
{
	int	size;

	size = 0;
	if (str[i] == 'c')
		size = ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		size = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'p')
		size = ft_void_ptr((va_arg(args, unsigned long int)));
	else if (str[i] == 'd' || str[i] == 'i')
		size = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		size = ft_putnbr(va_arg(args, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		size = ft_hex(va_arg(args, unsigned int), str[i]);
	else if (str[i] == '%')
		size = ft_putchar('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		num;

	num = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			num += ft_type(str, i + 1, args);
			i++;
		}
		else
		{
			num += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (num);
}
