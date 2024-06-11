/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 02:14:58 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 13:53:25 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_pos	set_pos(char prev_pos, char next_pos)
{
	t_pos	pos;

	pos.prev = prev_pos;
	pos.next = next_pos;
	return (pos);
}

static void	update_pos(t_array *game, size_t next_y, size_t next_x)
{
	t_pos	pos;

	pos.prev = '\0';
	pos.next = '\0';
	game->move_count++;
	if (game->map[next_y][next_x] == 'C' && game->num_of_collectibles--)
		pos = set_pos('0', 'P');
	if (game->map[next_y][next_x] == 'E' && game->num_of_collectibles)
		pos = set_pos('0', '.');
	if (game->map[next_y][next_x] == 'E' && !game->num_of_collectibles)
	{
		game->map[game->player_y][game->player_x] = '0';
		ft_printf("\033[1;34mMove count: %d\n", game->move_count);
		ft_printf("\033[1;32mYOU WON !!!\n");
		finish(game);
	}
	if (game->map[game->player_y][game->player_x] == '.')
		pos = set_pos('E', 'P');
	game->map[game->player_y][game->player_x] = pos.prev;
	game->map[next_y][next_x] = pos.next;
	game->player_y += next_y;
	game->player_x += next_x;
}

static void	ft_move_player(t_array *game, size_t y, size_t x)
{
	char	crnt_pos;
	char	next_pos;

	crnt_pos = game->map[game->player_y][game->player_x];
	next_pos = game->map[game->player_y + y][game->player_x + x];
	if (next_pos == '1')
		return ((void)ft_printf("\033[0;35mYou can't move into a wall\n"));
	else if (crnt_pos == '.' || next_pos == 'E' || next_pos == 'C')
		update_pos(game, game->player_y + y, game->player_x + x);
	else if (next_pos == '0')
	{
		game->map[game->player_y + y][game->player_x + x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->move_count++;
		game->player_y += y;
		game->player_x += x;
	}
	ft_printf("\033[1;34mMove count: %d\n", game->move_count);
}

int	game_hook(int keycode, t_array *game)
{
	get_player_position(game);
	if (keycode == 13 || keycode == 126)
		ft_move_player(game, -1, 0);
	else if (keycode == 1 || keycode == 125)
		ft_move_player(game, 1, 0);
	else if (keycode == 0 || keycode == 123)
	{
		game->player_position = 1;
		ft_move_player(game, 0, -1);
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->player_position = 0;
		ft_move_player(game, 0, 1);
	}
	if (keycode == 53)
	{
		ft_printf("\033[1;32mBye\n");
		finish(game);
	}
	img_put(game);
	return (0);
}

int	finish(t_array *game)
{
	ft_printf("\033[1;32mBye\n");
	exit_success(game);
	return (0);
}
