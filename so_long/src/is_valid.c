/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:33:18 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/23 14:33:20 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	is_valid(t_info *w, int x, int y)
{
	if (x <= 0 || y <= 0 || w->m_map.map[y][x] == '1')
		return (0);
	if (w->m_map.map[y][x] == 'E' && w->m_map.collected != w->m_map.to_collect)
		return (0);
	if (x <= 0 || y <= 0 || w->m_map.map[y][x] == 'C')
	{
		w->m_map.map[y][x] = '0';
		w->m_map.collected += 1;
		if (w->m_map.collected == w->m_map.to_collect)
		{
			mlx_destroy_image(w->id_mlx, w->m_exit.img_ptr);
			w->m_exit.img_ptr = mlx_xpm_file_to_image(w->id_mlx,
					"./sprites/st1.xpm", &w->m_exit.height, &w->m_exit.width);
		}
	}
	return (1);
}

int	valid_path(t_map *m_map, size_t x, size_t y)
{
	char	**map;
	size_t	i;

	m_map->reachable = 0;
	m_map->valid_exit = 0;
	i = 0;
	allocate_map(m_map, m_map->height, &map);
	check_c(m_map, map, x, y);
	while (i < m_map->height)
		free(map[i++]);
	free(map);
	allocate_map(m_map, m_map->height, &map);
	check_exit(m_map, map, x, y);
	i = 0;
	while (i < m_map->height)
		free(map[i++]);
	free(map);
	if ((m_map->reachable == m_map->to_collect) && m_map->valid_exit)
		return (1);
	ft_printf("Error\n");
	ft_printf("/!\\ Can't access all collectibles, or exit is blocked\n");
	return (0);
}

void	check_exit(t_map *m_map, char **map, size_t x, size_t y)
{
	if (x >= m_map->lenght || x <= 0 || y <= 0 || y > m_map->height
		|| map[y][x] == 'X' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
	{
		m_map->valid_exit += 1;
		map[y][x] = 'X';
	}
	if (map[y][x] != '1')
		map[y][x] = 'X';
	check_exit(m_map, map, x + 1, y);
	check_exit(m_map, map, x - 1, y);
	check_exit(m_map, map, x, y + 1);
	check_exit(m_map, map, x, y - 1);
}

void	check_c(t_map *m_map, char **map, size_t x, size_t y)
{
	if (x >= m_map->lenght || x <= 0 || y <= 0 || y > m_map->height
		|| map[y][x] == 'X' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'C')
	{
		m_map->reachable += 1;
		map[y][x] = 'X';
	}
	if (map[y][x] != '1')
		map[y][x] = 'X';
	check_c(m_map, map, x + 1, y);
	check_c(m_map, map, x - 1, y);
	check_c(m_map, map, x, y + 1);
	check_c(m_map, map, x, y - 1);
}

int	char_is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	return (0);
}
