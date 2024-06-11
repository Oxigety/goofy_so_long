/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <lchapard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:34:20 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/23 14:34:22 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/map.h"

int	load_window(t_info *w)
{
	w->id_mlx = mlx_init();
	if (w->id_mlx == NULL)
	{
		ft_printf(" Error \n/!\\ mlx init failed!\n");
		free_map(&w->m_map);
		exit(0);
	}
	w->id_wind = mlx_new_window(w->id_mlx,
			w->w_lenght, w->w_height, "Funny cow goes brrrr");
	if (w->id_wind == NULL)
	{
		mlx_destroy_display(w->id_mlx);
		free(w->id_mlx);
		ft_printf(" Error \n/!\\ couldn't open window!\n");
		free_map(&w->m_map);
		exit(0);
	}
	return (1);
}

void	free_mlx_map(t_info *w)
{
	mlx_destroy_display(w->id_mlx);
	free(w->id_mlx);
	free_map(&w->m_map);
	exit(0);
}

int	free_window(t_info *w)
{
	if (w->player.img_ptr != NULL)
		mlx_destroy_image(w->id_mlx, w->player.img_ptr);
	if (w->m_wall.img_ptr != NULL)
		mlx_destroy_image(w->id_mlx, w->m_wall.img_ptr);
	if (w->m_col.img_ptr != NULL)
		mlx_destroy_image(w->id_mlx, w->m_col.img_ptr);
	if (w->m_exit.img_ptr != NULL)
		mlx_destroy_image(w->id_mlx, w->m_exit.img_ptr);
	if (w->m_bck.img_ptr != NULL)
		mlx_destroy_image(w->id_mlx, w->m_bck.img_ptr);
	mlx_destroy_window(w->id_mlx, w->id_wind);
	free_mlx_map(w);
	return (0);
}

void	draw_all(t_info *wind)
{
	set_arena(wind, 0, 0);
	mlx_put_image_to_window(wind->id_mlx, wind->id_wind, wind->m_bck.img_ptr,
		wind->player.x, wind->player.y);
	mlx_put_image_to_window(wind->id_mlx, wind->id_wind, wind->player.img_ptr,
		wind->player.x, wind->player.y);
}

void	set_arena(t_info *w, size_t x, size_t y)
{
	while (y < w->m_map.height)
	{
		x = 0;
		while (x < w->m_map.lenght && w->m_map.map[y][x])
		{
			if (w->m_map.map[y][x] == '1')
				mlx_put_image_to_window(w->id_mlx, w->id_wind,
					w->m_wall.img_ptr, (SPRITE_SIZE * x), (SPRITE_SIZE * y));
			else if (w->m_map.map[y][x] == 'C')
				mlx_put_image_to_window(w->id_mlx, w->id_wind,
					w->m_col.img_ptr, (SPRITE_SIZE * x), (SPRITE_SIZE * y));
			else if (w->m_map.map[y][x] == 'E')
				mlx_put_image_to_window(w->id_mlx, w->id_wind,
					w->m_exit.img_ptr, (SPRITE_SIZE * x), (SPRITE_SIZE * y));
			else
				mlx_put_image_to_window(w->id_mlx, w->id_wind,
					w->m_bck.img_ptr, (SPRITE_SIZE * x), (SPRITE_SIZE * y));
			x++;
		}
		y++;
	}
}
