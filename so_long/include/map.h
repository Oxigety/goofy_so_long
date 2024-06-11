/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:30:47 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/03 12:30:51 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx_int.h"
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# define SPRITE_SIZE 64
# define MAX_HEIGHT 2100
# define MAX_LENGHT 3905

typedef struct t__my_image
{
	int		width;
	int		height;
	int		x;
	int		y;
	void	*img_ptr;
}				t_image;

typedef struct t_my_map
{
	char			**map;
	char			*name;
	size_t			lenght;
	size_t			height;
	size_t			to_collect;
	size_t			collected;
	size_t			reachable;
	size_t			valid_exit;
	unsigned int	nb_mv;
}				t_map;

typedef struct t_w_info
{
	void	*id_mlx;
	void	*id_wind;
	size_t	w_height;
	size_t	w_lenght;
	t_image	player;
	t_image	m_wall;
	t_image	m_col;
	t_image	m_exit;
	t_image	m_bck;
	t_map	m_map;
}				t_info;

void	display_map(char **map);
int		load_window(t_info *w);
void	load_sprites(t_info *w);
int		count_obj(t_map *m_map, char c, size_t x, size_t y);
int		count_is_valid(t_info *w);
int		map_is_valid(t_info *w);
int		char_is_valid(char c);
int		is_valid(t_info *w, int x, int y);
int		valid_path(t_map *m_map, size_t x, size_t y);
int		check_borders(t_map *m_map, size_t x, size_t y);
int		check_line_size(t_map *m_map);
void	check_c(t_map *m_map, char **map, size_t x, size_t y);
void	check_exit(t_map *m_map, char **map, size_t x, size_t y);
size_t	ft_strlenmap(const char *s);
int		get_info_map(t_map *m_map, size_t *w_height, size_t *w_widht);
void	free_mlx_map(t_info *w);
int		free_window(t_info *w);
int		free_map(t_map *m_map);
int		allocate_map(t_map *m_map, size_t m_height, char ***map);
int		no_events(t_info *wind);
void	set_arena(t_info *w, size_t x, size_t y);
void	set_object(t_info *w, char c, int *x_obj, int *y_obj);
void	moove_h(int id_key, t_info *w);
void	moove_v(int id_key, t_info *w);
int		deal_key(int id_key, t_info *w);
int		no_events(t_info *w);
void	draw_all(t_info *wind);
void	name_is_valid(char *str);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif