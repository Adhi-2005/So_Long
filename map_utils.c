/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:11:35 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 13:33:04 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_character(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C')
	{
		ft_printf("\033[1;31m(ERROR) Invalid characters in Map....!");
		return (0);
	}
	return (1);
}

int	check_for_game_objects(t_array *map_array)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < map_array->breadth)
	{
		j = 0;
		while (j < map_array->length)
		{
			if (!is_valid_character(map_array->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	create_array_for_map(char *str, t_array *area)
{
	char	*line;
	int		fd;
	size_t	index;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("\033[1;31m(ERROR) Unable to open the file...!");
	index = 0;
	area->map = malloc(sizeof(char *) * (area->breadth + 1));
	if (!area->map)
		perror("\033[1;31m(ERROR) Unable to malloc...!");
	area->map_cpy = malloc(sizeof(char *) * (area->breadth + 1));
	if (!area->map_cpy)
		perror("\033[1;31m(ERROR) Unable to malloc...!");
	line = get_next_line(fd);
	while (line)
	{
		area->map[index] = line;
		area->map_cpy[index] = ft_strdup(area->map[index]);
		line = get_next_line(fd);
		index++;
	}
	area->map[index] = NULL;
	area->map_cpy[index] = NULL;
	close(fd);
}

void	display_error(char *line, int fd)
{
	ft_printf("\033[1;31m(ERROR) Map not valid");
	free(line);
	close(fd);
	exit(1);
}

void	dimention_check(char *str, t_array *area)
{
	char	*line;
	int		fd;
	size_t	expected_length;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[1;31m(ERROR) Unable to open the file...!");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		area->length = ft_strlen(line);
		if (area->breadth == 0)
			expected_length = area->length;
		else if (expected_length != area->length)
			display_error(line, fd);
		area->breadth++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
