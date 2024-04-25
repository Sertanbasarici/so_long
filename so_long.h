/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:12 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/25 15:34:36 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minilibx/mlx.h"
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"
typedef struct s_game
{
	char	*map;
	int		money;
	int		counter;
	int		width;
	int		height;
	int		start;
	int		end;
	void	*floor;
	void	*character;
	void	*wall;
	void	*collectable;
	void	*exit;
	void	*windows;
	void	*mlx_start;
}	t_game;


#endif