/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:49:05 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:52:53 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_moves_to_window(t_data *g)
{
	char	*string;

	string = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->win, 5, 5, 1409999, string);
	free(string);
}

int	update(t_data *g)
{
	mlx_clear_window(g->mlx, g->win);
	render_frame(g);
	put_player(g);
	if (BONUS)
	{
		put_enemys(g);
		game_moves_to_window(g);
		coin_animation(g);
		enemy_animation(g);
		move_enemy(g);
		player_animation(g);
	}
	return (0);
}

int	close_win(t_data *g)
{
	int	i;

	i = -1;
	while (g->map.map[++i])
		free(g->map.map[i]);
	if (g->mlx)
	{
		mlx_clear_window(g->mlx, g->win);
		mlx_destroy_window(g->mlx, g->win);
	}
	exit (0);
}

void	start(t_data *g)
{
	err_init(g);
	map_init(g);
	create_map(g);
	check_map_rules(g);
}

int	main(int argc, char **argv)
{
	t_data	g;

	if (argc != 2)
	{
		if (argc > 2)
			ft_putstr_fd("Error\nTo many arguments.\n", 1);
		if (argc == 1)
			ft_putstr_fd("Error\nNo arguments.\n", 1);
		exit (1);
	}
	g.file_name = argv[1];
	g.mlx = NULL;
	start(&g);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, (int)g.map.len * X, \
	(int)(g.map.rows - 1) *X, "So long!");
	read_xpm(&g);
	mlx_hook(g.win, 2, 0, buttons_hook, (void *)&g);
	mlx_hook(g.win, 17, 0L, close_win, (void *)&g);
	mlx_loop_hook(g.mlx, update, (void *)&g);
	mlx_loop(g.mlx);
}
