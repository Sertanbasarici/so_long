/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:41:37 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/29 21:19:47 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_images(t_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx_start,
			"images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx_start,
			"images/wall.xpm", &i, &j);
	game->character = mlx_xpm_file_to_image(game->mlx_start,
			"images/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx_start,
			"images/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx_start,
			"images/coin.xpm", &i, &j);
	if (!(game->floor) || !(game->wall) || !(game->character) || !(game->exit) || !(game->collectable))
		ft_error(1);
}

void	put_images(t_game *game)
{
	int	i;
	int	y;

	i = 0;
	while (i < ft_strlen(game->map))
	{
		y = i / game->width;
		if (game->map[i] == '1')
			mlx_put_image_to_window(game->mlx_start, game->windows,
				game->wall, (i % game->width) * 50, y * 50);
		if (game->map[i] == '0')
			mlx_put_image_to_window(game->mlx_start, game->windows,
				game->floor, (i % game->width) * 50, y * 50);
		if (game->map[i] == 'C')
			mlx_put_image_to_window(game->mlx_start, game->windows,
				game->collectable, (i % game->width) * 50, y * 50);
		if (game->map[i] == 'P')
			mlx_put_image_to_window(game->mlx_start, game->windows,
				game->character, (i % game->width) * 50, y * 50);
		if (game->map[i] == 'E')
			mlx_put_image_to_window(game->mlx_start, game->windows,
				game->exit, (i % game->width) * 50, y * 50);
		i++;
	}
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game -> mlx_start, game -> windows);
	free(game -> mlx_start);
	free(game -> map);
	exit(0);
}

int	move(int direct, t_game *game)
{
	if ((game -> start) + direct < 0
		|| (game -> start) + direct >= ft_strlen(game -> map))
		return (0);
	if ((game -> map)[(game -> start) + direct] != '1')
	{
		game -> start += direct;
		if ((game -> map)[(game -> start)] == 'C')
			game -> money -= 1;
		(game -> map)[game -> start] = 'P';
		if ((game -> start) - direct == game -> end)
			(game -> map)[(game -> start) - direct] = 'E';
		else
			(game -> map)[(game -> start) - direct] = '0';
	}
	else
		return (0);
	game -> counter += 1;
	ft_printf("Number of Movements: %d\n", game -> counter);
	return (1);
}

int	keys(int command, t_game *game)
{
	if (command == 53)
		exit_game(game);
	else if (command == 0 || command == 123)
		move(-1, game);
	else if (command == 2 || command == 124)
		move(1, game);
	else if (command == 13 || command == 126)
		move(-1 * (game -> width), game);
	else if (command == 1 || command == 125)
		move(game -> width, game);
	if (game -> start == game -> end && game -> money == 0)
	{
		ft_printf("Congrats!\n");
		exit_game(game);
	}
	put_images(game);
	return (1);
}
