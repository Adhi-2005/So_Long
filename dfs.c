/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:49:00 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/10 00:52:15 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(t_array *area, size_t y, size_t x)
{
	if (area->map_cpy[y][x] == 'E')
		area->exit_found = true;
	else if (area->map_cpy[y][x] == 'C')
		area->collectibles_got++;
	area->map_cpy[y][x] = '1';
	if (area->exit_found && area->collectibles_got == area->num_of_collectibles)
		area->is_valid_map = 1;
	if (!area->is_valid_map && area->map_cpy[y][x + 1] != '1')
		dfs(area, y, x + 1);
	if (!area->is_valid_map && area->map_cpy[y][x - 1] != '1')
		dfs(area, y, x - 1);
	if (!area->is_valid_map && area->map_cpy[y + 1][x] != '1')
		dfs(area, y + 1, x);
	if (!area->is_valid_map && area->map_cpy[y - 1][x] != '1')
		dfs(area, y - 1, x);
}

bool	is_valid_path(t_array *area)
{
	get_player_position(area);
	get_number_of_collectibles(area);
	dfs(area, area->player_y, area->player_x);
	if (!(area->is_valid_map))
		return (false);
	return (true);
}
