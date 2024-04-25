/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:28:51 by sebasari          #+#    #+#             */
/*   Updated: 2023/11/10 16:19:15 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_ptr_len(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

static	void	ft_put_ptr(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_ptr(nbr / 16);
		ft_put_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

int	ft_void_ptr(unsigned long long nbr)
{
	int	size;

	ft_putstr("0x");
	size = 2;
	if (nbr == 0)
		size += ft_putchar('0');
	else
	{
		size += ft_ptr_len(nbr);
		ft_put_ptr(nbr);
	}
	return (size);
}
