/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:10:23 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/25 16:00:29 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps(t_game *game, char *path)
{
	map_read(game, path);
	control_map(game);
	control_check(game);
}

int	take_fd(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	if (len < 9 || path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b' || path[len - 3] != '.')
		ft_error(10);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(9);
	return (fd);
}

int	map_read(t_game *game, char *path)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = take_fd(path);
	line = get_next_line(fd);
	game -> map = 0;
	game -> width = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) != game -> width)
			ft_error(1);
		game->map = ft_strjoin(game->map, line);
		height++;
		free(line);
		if (line && line[ft_strlen(line) - 1] != '\n')
			line = ft_strjoin(line, "\n");
	}
	game -> height = height;
	free(line);
	close(fd);
	return (0);
}

int	control_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game -> height)
	{
		if (game -> map[j] != '1' && game -> map[j + game->width - 2] != '1')
			ft_error(2);
		j += game->width;
		i++;
	}
	i = 0;
	while (i < game -> width - 1)
	{
		if (game -> map[i] != '1' && game -> map[i + game -> width * game -> height - 1])
			ft_error(2);
		i++;
	}
	return (1);
}

int	counter(char *map, char c)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

int	control_check(t_game *game)
{
	if (counter(game->map, 'P') != 1)
		ft_error(3);
	if (counter(game->map, 'E') != 1)
		ft_error(4);
	if (counter(game->map, 'C') < 1)
		ft_error(5);
	if (counter(game->map, '1') + counter(game->map, 'P') + counter(game->map, 'E') + counter(game->map, 'C') + counter(game->map, '0') != (game->height * game->width - 1))
		ft_error(6);
	game -> money = counter(game->map, 'C');
	return (1);
}

void	begin_end(t_game *game)
{
	int i;

	i = 0;
	while (game -> map[i])
	{
		if (game -> map[i] == 'P')
		{
			game -> start = i;
			game -> counter = 0;
		}
		else if (game -> map[i] == 'E')
			game -> end = i;
		i++;
	}
	return (1);
}