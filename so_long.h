/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:26:12 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/27 21:50:20 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
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

void	ft_error(int num);
void	maps(t_game *game, char *path);
int		take_fd(char *path);
int		map_read(t_game *game, char *path);
int		control_map(t_game *game);
int		counter(char *map, char c);
int		control_check(t_game *game);
void	begin_end(t_game *game);
int		dfs_c(t_game *game, int i, char *str);
int		dfs_use_c(t_game *game);
int		dfs_e(t_game *game, int i, char *str);
int		dfs_use_e(t_game *game);
int		keys(int command, t_game *game);
int		move(int direct, t_game *game);
void	get_images(t_game *game);
void	put_images(t_game *game);

#endif