/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:26:11 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/09 03:52:07 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_my_map_is_okay(char *str)
{
	int		fd;
	size_t	read_bytes;
	char	buf[1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("\033[1;31m(ERROR) File not found....");
		return (0);
	}
	read_bytes = read(fd, buf, 1);
	if (read_bytes == 0)
	{
		ft_printf("\033[1;31m(ERROR) No contents in File....!");
		return (0);
		close(fd);
	}
	close(fd);
	return (1);
}

int	extention_check(char *str)
{
	if (str[0] == '.' && str[1] == 'b' && str[2] == 'e'
		&& str[3] == 'r' && str[4] == '\0')
	{
		ft_printf("\033[1;31m(ERROR) File name is invalid...!");
		return (0);
	}
	if (str[0] == '\0')
	{
		ft_printf("\033[1;31m(ERROR) File name cannot be empty\n");
		return (0);
	}
	if (!is_my_map_is_okay(str))
		return (0);
	return (1);
}

int	check_file_extension(char *str)
{
	char	*main_extention;
	int		i;
	int		j;

	i = 0;
	j = 4;
	main_extention = ".ber";
	while (str[i])
		i++;
	i--;
	j--;
	while (j >= 0)
	{
		if (str[i] != main_extention[j])
		{
			ft_printf("\033[1;31m(ERROR) Wrong file extention....!");
			return (0);
		}
		i--;
		j--;
	}
	if (!extention_check(str))
		return (0);
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	get_number_of_collectibles(t_array *area)
{
	size_t	i;
	size_t	j;
	size_t	collectible;

	collectible = 0;
	j = 0;
	i = 0;
	while (i < area->breadth)
	{
		j = 0;
		while (j < area->length)
		{
			if (area->map[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	area->num_of_collectibles = collectible;
}
