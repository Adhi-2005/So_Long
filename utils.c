/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 00:52:00 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 13:32:55 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char ***map)
{
	int	i;

	if (!(*map))
		return ;
	i = 0;
	while ((*map)[i])
		free((*map)[i++]);
	free(*map);
	(*map) = NULL;
}

void	exit_error(t_array *array)
{
	if (array->map)
		free_map(&(array->map));
	if (array->map_cpy)
		free_map(&(array->map_cpy));
	exit(EXIT_FAILURE);
}

void	exit_success(t_array *array)
{
	if (array->map)
		free_map(&(array->map));
	if (array->map_cpy)
		free_map(&(array->map_cpy));
	exit(EXIT_SUCCESS);
}
