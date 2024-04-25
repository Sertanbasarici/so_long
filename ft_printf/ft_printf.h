/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:44:38 by sebasari          #+#    #+#             */
/*   Updated: 2023/11/24 11:16:27 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_type(const char *str, size_t i, va_list args);
int		ft_putstr(char *s);
int		ft_putchar(int c);
int		ft_putnbr(long n);
int		ft_hex(unsigned int nbr, char c);
int		ft_void_ptr(unsigned long long nbr);

#endif