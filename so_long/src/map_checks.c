/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:33:37 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/23 14:33:38 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	check_borders(t_map *m_map, size_t x, size_t y)
{
	while (y < m_map->height - 1)
	{
		if ((m_map->map[y][0] == '1') &&
				(m_map->map[y][m_map->lenght - 1] == '1'))
			y++;
		else
			return (1);
	}
	while (x < m_map->lenght - 2)
	{
		if ((m_map->map[0][x] == '1') &&
				(m_map->map[m_map->height - 1][x] == '1'))
			x++;
		else
			return (1);
	}
	return (0);
}

int	check_line_size(t_map *m_map)
{
	size_t	l_lenght;
	size_t	i;

	i = 0;
	l_lenght = m_map->lenght;
	while (i < m_map->height - 1)
	{
		if (ft_strlenmap(m_map->map[i]) != l_lenght)
			return (1);
		i++;
	}
	if (ft_strlenmap(m_map->map[m_map->height - 1]) != l_lenght)
		return (1);
	return (0);
}

int	count_is_valid(t_info *w)
{
	if ((w->w_height > MAX_HEIGHT) || (w->w_lenght) > MAX_LENGHT)
	{
		ft_printf("Error!\n");
		ft_printf("/!\\ MAP IS TOO BIG FOR THE SCREEN!\n");
		return (0);
	}
	if (count_obj(&w->m_map, 'P', 0, 0) || count_obj
		(&w->m_map, 'E', 0, 0) || !count_obj(&w->m_map, 'C', 0, 0))
	{
		ft_printf("Error!\n");
		ft_printf("/!\\ NEED 1 EXIT/PLAYER AND AT LEAST 1 COLLECTIBLE!\n");
		return (0);
	}
	return (1);
}

int	map_is_valid(t_info *w)
{
	if ((check_line_size(&w->m_map)))
	{
		ft_printf("Error!\n");
		ft_printf("/!\\ MAP MUST BE A RECTANGLE!\n");
		return (0);
	}
	if (check_borders(&w->m_map, 0, 0))
	{
		ft_printf("Error!\n");
		ft_printf("/!\\ MAP NEEDS TO BE SURROUNDED BY WALLS!\n");
		return (0);
	}
	return (1);
}

int	count_obj(t_map *m_map, char c, size_t x, size_t y)
{
	int	cpt;

	cpt = 0;
	while (y < m_map->height)
	{
		x = 0;
		while (x < m_map->lenght && m_map->map[y][x])
		{
			if (m_map->map[y][x] == c)
				cpt += 1;
			if (!char_is_valid(m_map->map[y][x]))
				return (ft_printf("Error\nFOUND UNEXPECTED CHARACTER!\n"));
			x++;
		}
		y++;
	}
	if ((cpt == 1) && (c == 'E' || c == 'P'))
		return (0);
	else if (c == 'E' || c == 'P')
		return (ft_printf("Error\n/!\\ WRONG NB OF PLAYERS OR EXITS!\n"));
	else
		m_map->to_collect = cpt;
	return (cpt);
}
