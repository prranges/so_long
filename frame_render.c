/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:45:42 by prranges          #+#    #+#             */
/*   Updated: 2021/10/07 10:45:44 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_enemys(t_data *g)
{
	int	i;

	i = 0;
	while (i < g->map.e && !g->f_loose && !g->f_win)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->e.t_enemy, \
		g->e.e_x[i], g->e.e_y[i]);
		if (g->p.p_x == g->e.e_x[i] && g->p.p_y == g->e.e_y[i])
			g->f_loose++;
		i++;
	}
	if (g->f_loose)
	{
		mlx_clear_window(g->mlx, g->win);
		mlx_put_image_to_window(g->mlx, g->win, g->t_you_loose, \
		(g->map.len * X / 2) - 40, (g->map.rows - 1) * X / 2);
		mlx_put_image_to_window(g->mlx, g->win, g->e.t_enemy, \
		(g->map.len * X / 2) - 40, (g->map.rows - 1) * X / 2);
	}
}

void	put_player(t_data *g)
{
	if (g->map.exit == -1 && \
		g->map.map[(g->p.p_y - X) / X][g->p.p_x / X] == 'E' && !g->f_win)
		g->f_win++;
	if (g->f_win)
	{
		mlx_clear_window(g->mlx, g->win);
		mlx_put_image_to_window(g->mlx, g->win, g->t_you_win, \
		(g->map.len * 16) - 40, (g->map.rows - 1) * 16);
		mlx_put_image_to_window(g->mlx, g->win, g->c.t_money, \
		(g->map.len * 16) - 40, (g->map.rows - 1) * 16);
	}
	if (!g->f_win && !g->f_loose)
		mlx_put_image_to_window(g->mlx, g->win, g->p.t_player, \
		g->p.p_x, g->p.p_y);
}

void	render_frame_exit(t_data *g)
{
	if (g->map.coin > 0)
		mlx_put_image_to_window(g->mlx, g->win, g->t_c_exit, \
		g->i, g->j);
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->t_o_exit, \
		g->i, g->j);
		g->map.exit = -1;
	}
}

void	render_frame_coin(t_data *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->c.t_money, g->i, g->j);
	if (g->i == g->p.p_x && g->j == g->p.p_y && g->map.coin > 0)
	{
		g->map.map[g->map.j][g->map.i] = '0';
		g->map.coin--;
	}
}

void	render_frame(t_data *g)
{
	g->map.i = -1;
	g->map.j = -1;
	g->j = X;
	while (g->map.map[++g->map.j] && !g->f_win)
	{
		g->i = 0;
		g->map.i = -1;
		while (g->map.map[g->map.j][++g->map.i] != '\0')
		{
			if (g->map.map[g->map.j][g->map.i] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->t_wall, g->i, g->j);
			if (g->map.map[g->map.j][g->map.i] != '1')
				mlx_put_image_to_window(g->mlx, g->win, g->t_floor, g->i, g->j);
			if (g->map.map[g->map.j][g->map.i] == 'C')
				render_frame_coin(g);
			if (g->map.map[g->map.j][g->map.i] == 'E')
				render_frame_exit(g);
			g->i += X;
		}
		g->j += X;
	}
}
