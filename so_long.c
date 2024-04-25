/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:36:36 by sebasari          #+#    #+#             */
/*   Updated: 2024/04/25 16:41:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argn, char **argv)
{
	t_game *game;

	game = malloc(sizeof(game));
	if (argn != 2)
		ft_error(0);
	maps(game, argv[1]);
	game -> mlx_start = mlx_init();
	game -> windows = mlx_new_window(game -> mlx_start, (game -> width - 1) * 50 , game -> height * 50, "so_long");
	put_images(game);
}

void ft_error(int num)
{
	if (num == 0)
		ft_printf("please enter valid argument number!");
	else if (num == 1)
		ft_printf("invalid width of ");
	else if (num == 2)
		ft_printf("error in walls");
	else if (num == 3)
		ft_printf("where is the player !!!");
	else if (num == 4)
		ft_printf("where is the exit !!!");
	else if (num == 5)
		ft_printf("Not enough money !!!");
	else if (num == 6)
		ft_printf("map size and character numbers are not matching !!!");
	else if (num == 7)

	else if (num == 9)
		ft_printf("something wrong in map like walls");
	else if (num == 10)
		ft_printf("invalid extension not .ber!!!");
}