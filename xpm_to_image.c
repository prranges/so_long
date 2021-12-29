/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:42:11 by prranges          #+#    #+#             */
/*   Updated: 2021/09/19 12:59:30 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_player_xpm(t_data *g)
{
	int		w;
	int		h;

	g->p.t_player_d1 = mlx_xpm_file_to_image(g->mlx, PLAYER_D1, &w, &h);
	g->p.t_player_d2 = mlx_xpm_file_to_image(g->mlx, PLAYER_D2, &w, &h);
	g->p.t_player_d3 = mlx_xpm_file_to_image(g->mlx, PLAYER_D3, &w, &h);
	g->p.t_player_d4 = mlx_xpm_file_to_image(g->mlx, PLAYER_D4, &w, &h);
	g->p.t_player_d5 = mlx_xpm_file_to_image(g->mlx, PLAYER_D5, &w, &h);
	g->p.t_player_l2 = mlx_xpm_file_to_image(g->mlx, PLAYER_L2, &w, &h);
	g->p.t_player_l3 = mlx_xpm_file_to_image(g->mlx, PLAYER_L3, &w, &h);
	g->p.t_player_l4 = mlx_xpm_file_to_image(g->mlx, PLAYER_L4, &w, &h);
	g->p.t_player_l5 = mlx_xpm_file_to_image(g->mlx, PLAYER_L5, &w, &h);
	g->p.t_player_u2 = mlx_xpm_file_to_image(g->mlx, PLAYER_U2, &w, &h);
	g->p.t_player_u3 = mlx_xpm_file_to_image(g->mlx, PLAYER_U3, &w, &h);
	g->p.t_player_u4 = mlx_xpm_file_to_image(g->mlx, PLAYER_U4, &w, &h);
	g->p.t_player_u5 = mlx_xpm_file_to_image(g->mlx, PLAYER_U5, &w, &h);
	g->p.t_player_r2 = mlx_xpm_file_to_image(g->mlx, PLAYER_R2, &w, &h);
	g->p.t_player_r3 = mlx_xpm_file_to_image(g->mlx, PLAYER_R3, &w, &h);
	g->p.t_player_r4 = mlx_xpm_file_to_image(g->mlx, PLAYER_R4, &w, &h);
	g->p.t_player_r5 = mlx_xpm_file_to_image(g->mlx, PLAYER_R5, &w, &h);
	g->p.t_player = g->p.t_player_d1;
}

void	read_xpm(t_data *g)
{
	int		w;
	int		h;

	g->t_floor = mlx_xpm_file_to_image(g->mlx, FLOOR, &w, &h);
	g->t_wall = mlx_xpm_file_to_image(g->mlx, WALL, &w, &h);
	g->c.t_money_1 = mlx_xpm_file_to_image(g->mlx, MONEY1, &w, &h);
	g->c.t_money_2 = mlx_xpm_file_to_image(g->mlx, MONEY2, &w, &h);
	g->c.t_money_3 = mlx_xpm_file_to_image(g->mlx, MONEY3, &w, &h);
	g->c.t_money_4 = mlx_xpm_file_to_image(g->mlx, MONEY4, &w, &h);
	g->c.t_money_5 = mlx_xpm_file_to_image(g->mlx, MONEY5, &w, &h);
	g->c.t_money_6 = mlx_xpm_file_to_image(g->mlx, MONEY6, &w, &h);
	g->c.t_money_7 = mlx_xpm_file_to_image(g->mlx, MONEY7, &w, &h);
	g->c.t_money = g->c.t_money_1;
	g->t_c_exit = mlx_xpm_file_to_image(g->mlx, C_EXIT, &w, &h);
	g->t_o_exit = mlx_xpm_file_to_image(g->mlx, O_EXIT, &w, &h);
	read_player_xpm(g);
	g->e.t_enemy1 = mlx_xpm_file_to_image(g->mlx, ENEMY1, &w, &h);
	g->e.t_enemy2 = mlx_xpm_file_to_image(g->mlx, ENEMY2, &w, &h);
	g->e.t_enemy3 = mlx_xpm_file_to_image(g->mlx, ENEMY3, &w, &h);
	g->e.t_enemy4 = mlx_xpm_file_to_image(g->mlx, ENEMY4, &w, &h);
	g->e.t_enemy5 = mlx_xpm_file_to_image(g->mlx, ENEMY5, &w, &h);
	g->e.t_enemy6 = mlx_xpm_file_to_image(g->mlx, ENEMY6, &w, &h);
	g->e.t_enemy = g->e.t_enemy1;
	g->t_you_win = mlx_xpm_file_to_image(g->mlx, U_WIN, &w, &h);
	g->t_you_loose = mlx_xpm_file_to_image(g->mlx, U_LOOSE, &w, &h);
}
