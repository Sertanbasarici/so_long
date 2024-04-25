/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:37:44 by sebasari          #+#    #+#             */
/*   Updated: 2023/11/11 15:34:38 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	char	c;
	long	size;

	size = 0;
	if (n < 0)
	{
		size = 1;
		n = n * -1;
		write(1, "-", 1);
	}
	if (n > 9)
	{
		size += ft_putnbr(n / 10);
		size += ft_putnbr(n % 10);
	}
	else
	{
		c = '0' + n;
		size += write(1, &c, 1);
	}
	return (size);
}
