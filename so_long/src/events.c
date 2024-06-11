/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:12:35 by lchapard          #+#    #+#             */
/*   Updated: 2023/12/21 17:12:39 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/map.h"

int	no_events(t_info *w)
{
	if ((w->player.x == w->m_exit.x) && (w->player.y == w->m_exit.y))
	{
		if (w->m_map.collected == w->m_map.to_collect)
		{
			ft_printf("You won in %u mooves ! GG WP :D\n", w->m_map.nb_mv);
			free_window(w);
		}
	}
	return (0);
}

void	moove_h(int id_key, t_info *w)
{
	if (id_key == XK_d)
	{
		if ((w->id_wind != NULL) && is_valid(w,
				(w->player.x) / SPRITE_SIZE + 1, w->player.y / SPRITE_SIZE))
		{
			w->player.x += SPRITE_SIZE;
			w->m_map.nb_mv += 1;
			ft_printf("Mooves : %u\n", w->m_map.nb_mv);
		}
	}
	else
	{
		if ((w->id_wind != NULL) && is_valid(w,
				(w->player.x) / SPRITE_SIZE - 1, w->player.y / SPRITE_SIZE))
		{
			w->player.x -= SPRITE_SIZE;
			w->m_map.nb_mv += 1;
			ft_printf("Mooves : %u\n", w->m_map.nb_mv);
		}
	}
	draw_all(w);
}

void	moove_v(int id_key, t_info *w)
{
	if (id_key == XK_s)
	{
		if ((w->id_wind != NULL) && is_valid(w,
				(w->player.x) / SPRITE_SIZE, w->player.y / SPRITE_SIZE + 1))
		{
			w->player.y += SPRITE_SIZE;
			w->m_map.nb_mv += 1;
			draw_all(w);
			ft_printf("Mooves : %u\n", w->m_map.nb_mv);
		}
	}
	else
	{
		if ((w->id_wind != NULL) && is_valid(w,
				(w->player.x) / SPRITE_SIZE, w->player.y / SPRITE_SIZE - 1))
		{
			w->player.y -= SPRITE_SIZE;
			w->m_map.nb_mv += 1;
			draw_all(w);
			ft_printf("Mooves : %u\n", w->m_map.nb_mv);
		}
	}
}

int	deal_key(int id_key, t_info *w)
{
	if (id_key == XK_Escape)
		free_window(w);
	if (id_key == XK_s || id_key == XK_w)
		moove_v(id_key, w);
	if (id_key == XK_d || id_key == XK_a)
		moove_h(id_key, w);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	w;

	if (argc != 2)
		return (ft_printf("Error\n/!\\ WRONG NB OF PARAMETERS!\n"));
	w.m_map.name = argv[1];
	if (get_info_map(&w.m_map, &w.w_height, &w.w_lenght))
		return (1);
	if (allocate_map(&w.m_map, w.m_map.height, &w.m_map.map))
		return (1);
	if (!count_is_valid(&w) || !map_is_valid(&w))
		return (free_map(&w.m_map));
	set_object(&w, 'P', &w.player.x, &w.player.y);
	set_object(&w, 'E', &w.m_exit.x, &w.m_exit.y);
	if (!valid_path(&w.m_map,
			w.player.x / SPRITE_SIZE, w.player.y / SPRITE_SIZE))
		return (free_map(&w.m_map));
	if (!load_window(&w))
		return (1);
	load_sprites(&w);
	draw_all(&w);
	mlx_hook(w.id_wind, KeyPress, KeyPressMask, deal_key, &w);
	mlx_hook(w.id_wind, DestroyNotify, StructureNotifyMask, free_window, &w);
	mlx_loop_hook(w.id_mlx, no_events, &w);
	mlx_loop(w.id_mlx);
	return (0);
}
