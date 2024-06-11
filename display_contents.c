/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_contents.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:50:40 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 13:53:16 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_array *game, char *img, int i, int j)
{
	int	width;
	int	height;

	width = game->img_width * j;
	height = game->img_height * i;
	mlx_put_image_to_window(game->mlx, game->win, img, width, height);
}

void	put_image_to_window(t_array *game, int i, int j)
{
	if (game->map[i][j] == '1')
		draw_image(game, game->wall, i, j);
	if (game->map[i][j] == 'E')
		draw_image(game, game->img_exit, i, j);
	else if (game->map[i][j] == 'C')
		draw_image(game, game->collectibles, i, j);
	else if (game->map[i][j] == 'P')
	{
		game->player_x = j;
		game->player_y = i;
		draw_image(game, game->pac_man_left, i, j);
	}
	else if (game->map[i][j] == '.')
	{
		game->player_x = j;
		game->player_y = i;
		draw_image(game, game->img_exit, i, j);
		draw_image(game, game->pac_man_left, i, j);
	}
}

int	img_put(t_array *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_background, game->img_width * j,
				game->img_height * i);
			put_image_to_window(game, i, j);
		}
		i++;
	}
	return (0);
}

void	load_images(t_array *game_map)
{
	game_map->img_width = 128;
	game_map->img_height = 128;
	game_map->pac_man_left = mlx_xpm_file_to_image(game_map->mlx,
			"images/PacMan(left)_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->collectibles = mlx_xpm_file_to_image(game_map->mlx,
			"images/collectible_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->wall = mlx_xpm_file_to_image(game_map->mlx,
			"images/Wall_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->img_background = mlx_xpm_file_to_image(game_map->mlx,
			"images/Background_image.xpm", &game_map->img_width,
			&game_map->img_height);
	game_map->img_exit = mlx_xpm_file_to_image(game_map->mlx,
			"images/exit_image.xpm", &game_map->img_width,
			&game_map->img_height);
	img_put(game_map);
	game_map->player_y = 0;
	game_map->player_x = 0;
	if (game_map->wall == NULL)
	{
		ft_printf("\033[1;31m(ERROR) Could not load wall image\n");
		exit(EXIT_FAILURE);
	}
}

void	main_window(t_array *area)
{
	area->mlx = mlx_init();
	area->win = mlx_new_window(area->mlx, area->length * 128,
			area->breadth * 128, "PAC MAN verson:Infinity");
	load_images(area);
	mlx_hook(area->win, 2, 1L << 0, game_hook, area);
	mlx_hook(area->win, 17, 1L << 0, finish, &area);
	mlx_loop(area->mlx);
	return ;
}
