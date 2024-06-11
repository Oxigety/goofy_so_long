/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:38:48 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/23 14:38:50 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

void	set_object(t_info *w, char c, int *x_obj, int *y_obj)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (y < w->m_map.height)
	{
		x = 0;
		while (x < w->m_map.lenght && w->m_map.map[y][x])
		{
			if (w->m_map.map[y][x] == 'P')
				w->m_map.collected = 0;
			if (w->m_map.map[y][x] == c)
			{
				*x_obj = x * SPRITE_SIZE;
				*y_obj = y * SPRITE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	load_sprites(t_info *w)
{
	w->player.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
			"./sprites/cowskt2.xpm", &w->player.height, &w->player.width);
	w->m_wall.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
			"./sprites/trees.xpm", &w->player.height, &w->player.width);
	w->m_col.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
			"./sprites/chocbarre.xpm", &w->m_col.height, &w->m_col.width);
	w->m_exit.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
			"./sprites/cdoor21.xpm", &w->m_exit.height, &w->m_exit.width);
	w->m_bck.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
			"./sprites/grass3.xpm", &w->m_bck.height, &w->m_bck.width);
	if (w->player.img_ptr == NULL || w->m_wall.img_ptr == NULL
		|| w->m_col.img_ptr == NULL || w->m_exit.img_ptr == NULL
		|| w->m_bck.img_ptr == NULL)
	{
		ft_printf("Error!\nCouldn't load sprites!");
		free_window(w);
	}
}

int	get_info_map(t_map *m_map, size_t *w_height, size_t *w_lenght)
{
	char	*str;
	int		fd;

	str = " ";
	m_map->height = 0;
	m_map->lenght = 0;
	m_map->nb_mv = 0;
	name_is_valid(m_map->name);
	fd = open(m_map->name, O_RDONLY);
	if (fd == -1)
		return (ft_printf(" /!\\ INVALID MAP NAME!\n"));
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
			m_map->lenght = ft_strlenmap(str);
		m_map->height += 1;
		free(str);
	}
	m_map->height -= 1;
	*w_height = m_map->height * SPRITE_SIZE;
	*w_lenght = m_map->lenght * SPRITE_SIZE;
	close(fd);
	return (0);
}

int	free_map(t_map *m_map)
{
	size_t	i;

	i = 0;
	while (i < m_map->height)
	{
		free(m_map->map[i]);
		i++;
	}
	free(m_map->map);
	return (0);
}

int	allocate_map(t_map *m_map, size_t m_height, char ***map)
{
	char	**row;
	size_t	i;
	int		fd;

	i = 0;
	fd = open(m_map->name, O_RDONLY);
	row = (char **)malloc(sizeof(char *) * m_height);
	if (row == NULL)
		return (1);
	while (i < m_height)
	{
		row[i] = get_next_line(fd);
		i++;
	}
	*map = row;
	close(fd);
	return (0);
}
