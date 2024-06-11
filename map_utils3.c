/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:52:26 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/10 00:48:42 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_wall(t_array *area)
{
	size_t	i;

	i = 0;
	while (i < area->length)
	{
		if (area->map[0][i] != '1' || area->map[area->breadth - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < area->breadth)
	{
		if (area->map[i][0] != '1' || area->map[i][area->length - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	objects_check_with_numbers(int player, int collectibles, int exit)
{
	if (player != 1 || collectibles < 1 || exit != 1)
	{
		ft_printf("\033[1;31m(ERROR) Input the objects correctly....!");
		return (0);
	}
	return (1);
}

int	check_other_object_conditions(t_array *area)
{
	static int	player;
	static int	collectibles;
	static int	exit;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < area->breadth)
	{
		j = 0;
		while (j < area->length)
		{
			if (area->map[i][j] == 'P')
				player++;
			else if (area->map[i][j] == 'C')
				collectibles++;
			else if (area->map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (objects_check_with_numbers(player, collectibles, exit) == 0)
		return (0);
	return (1);
}

void	get_player_position(t_array *area)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (y < area->breadth - 1)
	{
		x = 1;
		while (x < area->length - 1)
		{
			if (area->map[y][x] == 'P')
			{
				area->player_x = x;
				area->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
