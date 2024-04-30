/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_first_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:02:34 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/30 17:21:27 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs_use_e(t_game *game)
{
	char	*str;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	str = malloc(ft_strlen(game->map));
	if (!str)
		return (0);
	while (i < ft_strlen(game -> map))
	{
		str[i] = '0';
		i++;
	}
	if (dfs_e(game, game -> start, str) == 1)
		ret = 1;
	free(str);
	return (ret);
}

int	dfs_e(t_game *game, int i, char *str)
{
	if (str[i] == '1' || i < 0
		|| i > ft_strlen(game->map)
		|| (game->map)[i] == '1')
		return (0);
	str[i] = '1';
	if ((game->map)[i] == 'E')
		return (1);
	return (dfs_e(game, i + 1, str)
		|| dfs_e(game, i - 1, str)
		|| dfs_e(game, i + game->width, str)
		|| dfs_e(game, i - game->width, str));
}

int	dfs_use_c(t_game *game)
{
	char	*str;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	str = malloc(ft_strlen(game->map));
	if (!str)
		return (0);
	while (i < ft_strlen(game->map))
	{
		str[i] = '0';
		i++;
	}
	ret = dfs_c(game, game -> start, str);
	free(str);
	return (ret);
}

int	dfs_c(t_game *game, int i, char *str)
{
	int	coin_num;

	coin_num = 0;
	if (str[i] == '1' || i < 0
		|| i > ft_strlen(game->map)
		|| (game->map)[i] == '1')
		return (0);
	str[i] = '1';
	if ((game->map)[i] == 'C')
		coin_num = 1;
	return (dfs_c(game, i + 1, str)
		+ dfs_c(game, i - 1, str)
		+ dfs_c(game, i + game->width, str)
		+ dfs_c(game, i - game->width, str) + coin_num);
}

int	control_check(t_game *game)
{
	if (counter(game->map, 'P') != 1)
		ft_error(3);
	if (counter(game->map, 'E') != 1)
		ft_error(4);
	if (counter(game->map, 'C') < 1)
		ft_error(5);
	if (counter(game->map, '1') + counter(game->map, 'P')
		+ counter(game->map, 'E') + counter(game->map, 'C')
		+ counter(game->map, '0') != (game -> height) * (game -> width - 1))
		ft_error(6);
	game -> money = counter(game -> map, 'C');
	return (1);
}
