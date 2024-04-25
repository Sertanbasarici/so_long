/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:35:39 by sebasari          #+#    #+#             */
/*   Updated: 2023/11/24 11:01:24 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int nbr)
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

static	void	ft_put_hex(unsigned int nbr, char c)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, c);
		ft_put_hex(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else if (c == 'X')
			ft_putchar(nbr - 10 + 'A');
		else
		{
			ft_putchar(nbr - 10 + 'a');
		}
	}
}

int	ft_hex(unsigned int nbr, char c)
{
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_put_hex(nbr, c);
	return (ft_hex_len(nbr));
}
