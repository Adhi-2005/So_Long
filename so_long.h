/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:43:04 by adshafee          #+#    #+#             */
/*   Updated: 2024/04/15 13:15:41 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libftprintf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_pos
{
	char	prev;
	char	next;
}	t_pos;

typedef struct b_list
{
	size_t	length;
	size_t	breadth;
	char	**map;
	char	**map_cpy;
	size_t	player_y;
	size_t	player_x;
	bool	exit_found;
	int		collectibles_got;
	int		num_of_collectibles;
	int		count;
	int		collect_n;
	void	*mlx;
	void	*win;
	int		player_position;
	char	*img_background;
	char	*img_wall;
	char	*img_exit;
	char	*img_collectible;
	char	*img_player;
	int		move_count;
	int		end_game;
	int		img_width;
	int		img_height;
	char	**dup_map;
	char	*pac_man_right;
	char	*pac_man_left;
	char	*pac_man_down;
	char	*pac_man_up;
	char	*collectibles;
	char	*wall;
	int		is_valid_map;
}	t_array;

void	images_init(t_array *area);

// map_utils.c

void	dimention_check(char *str, t_array	*area);
void	create_array_for_map(char *str, t_array *area);
int		check_for_game_objects(t_array *map_array);

// map_utils2.c

size_t	word_count(const char *s, char c);
char	**ft_split(char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);

// map_utils3.c

int		check_map_wall(t_array *area);
int		check_other_object_conditions(t_array *area);
void	get_player_position(t_array *area);

// dfs.c

bool	is_valid_path(t_array *area);

// display_contents.c

void	main_window(t_array *game);
int		img_put(t_array *game);
void	load_images(t_array *game_map);

// controls.c

int		game_hook(int keycode, t_array *game);
int		finish(t_array *game);

// external_utils.c

int		check_file_extension(char *str);
char	*ft_strdup(const char *s);
void	get_number_of_collectibles(t_array *area);

// Utils
void	free_map(char ***map);
void	exit_error(t_array *array);
void	exit_success(t_array *array);

#endif