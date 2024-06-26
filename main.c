/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:36:36 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/30 19:47:48 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argn, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (argn != 2)
		ft_error(0);
	maps(game, argv[1]);
	game -> mlx_start = mlx_init();
	game -> windows = mlx_new_window(game -> mlx_start,
			((game -> width - 1) * 50), (game -> height * 50), "so_long");
	get_images(game);
	put_images(game);
	mlx_key_hook(game -> windows, keys, game);
	mlx_hook(game -> windows, 17, 0, (void *)exit, 0);
	mlx_loop(game -> mlx_start);
	return (0);
}

void	ft_error(int num)
{
	write(2, "Error\n", 6);
	if (num == 0)
		ft_printf("please enter valid argument number!\n");
	else if (num == 1)
		ft_printf("invalid width of\n");
	else if (num == 2)
		ft_printf("error in walls\n");
	else if (num == 3)
		ft_printf("where is the player !!!\n");
	else if (num == 4)
		ft_printf("where is the exit !!!\n");
	else if (num == 5)
		ft_printf("Not enough money !!!\n");
	else if (num == 6)
		ft_printf("map size and character numbers are not matching !!!\n");
	else if (num == 7)
		ft_printf("impossible to react to end !!!\n");
	else if (num == 8)
		ft_printf("all coins are not collectable!!!\n");
	else if (num == 9)
		ft_printf("Can not open that file\n");
	else if (num == 10)
		ft_printf("invalid extension not .ber!!!\n");
	exit(0);
}

void	ft_error_2(int num)
{
	write(2, "Error\n", 6);
	if (num == 0)
		ft_printf("there is no images put images\n");
	else if (num == 1)
		ft_printf("Empthy map !!!\n");
	exit(0);
}

void	begin_end(t_game *game)
{
	int	i;

	i = 0;
	while (game -> map[i])
	{
		if ((game -> map)[i] == 'P')
		{
			game -> start = i;
			game -> counter = 0;
		}
		else if ((game -> map)[i] == 'E')
			game -> end = i;
		i++;
	}
}
