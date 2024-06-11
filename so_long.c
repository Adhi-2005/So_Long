/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:29:53 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 14:00:38 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	images_init2(t_array *area)
{
	area->move_count = 0;
	area->player_position = 0;
	area->end_game = 0;
	area->img_width = 0;
	area->collect_n = 0;
	area->img_height = 0;
	area->pac_man_right = 0;
}

void	images_init(t_array *area)
{
	area->map = NULL;
	area->map_cpy = NULL;
	area->length = 0;
	area->breadth = 0;
	area->collectibles_got = 0;
	area->num_of_collectibles = 0;
	area->exit_found = 0;
	area->player_x = 0;
	area->player_y = 0;
	area->count = 0;
	area->is_valid_map = 0;
	area->mlx = NULL;
	area->win = NULL;
	area->img_background = NULL;
	area->img_wall = NULL;
	area->img_exit = NULL;
	area->img_collectible = NULL;
	area->img_player = NULL;
	images_init2(area);
}

static void	setup_game_objects(t_array *area)
{
	if (check_map_wall(area) == 0)
	{
		ft_printf("\033[1;31m(ERROR) Border of the map is not valid..\n");
		exit_error(area);
	}
	if (check_for_game_objects(area) == 0)
		exit_error(area);
	if (!check_other_object_conditions(area))
		exit_error(area);
	if (!is_valid_path(area))
	{
		ft_printf("\033[1;31m(ERROR) No valid Path....!!!");
		exit_error(area);
	}
	get_number_of_collectibles(area);
	area->breadth = area->breadth;
	area->length = area->length;
	main_window(area);
}

static void	parse_input_and_setup_game(char **av, t_array *area)
{
	if (!check_file_extension(av[1]))
		exit(EXIT_FAILURE);
	images_init(area);
	dimention_check(av[1], area);
	create_array_for_map(av[1], area);
	setup_game_objects(area);
	exit_success(area);
}

int	main(int ac, char **av)
{
	t_array	area;

	if (ac != 2)
	{
		ft_printf("\033[1;31m(ERROR) Input 2 arguments\n");
		exit(EXIT_FAILURE);
	}
	parse_input_and_setup_game(av, &area);
	return (0);
}
