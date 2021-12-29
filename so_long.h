/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prranges <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:43:37 by prranges          #+#    #+#             */
/*   Updated: 2021/09/16 15:51:32 by prranges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define X 32
# define ESC 53
# define LEFT 0
# define DOWN 1
# define UP 13
# define RIGHT 2
# define RESTART 15

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_coin
{
	void	*t_money;
	void	*t_money_1;
	void	*t_money_2;
	void	*t_money_3;
	void	*t_money_4;
	void	*t_money_5;
	void	*t_money_6;
	void	*t_money_7;
}				t_coin;

typedef struct s_enemy
{
	int		e_x[50];
	int		e_y[50];
	void	*t_enemy;
	void	*t_enemy1;
	void	*t_enemy2;
	void	*t_enemy3;
	void	*t_enemy4;
	void	*t_enemy5;
	void	*t_enemy6;
}				t_enemy;

typedef struct s_player
{
	int		p_x;
	int		p_y;
	void	*t_player;
	void	*t_player_d1;
	void	*t_player_d2;
	void	*t_player_d3;
	void	*t_player_d4;
	void	*t_player_d5;
	void	*t_player_l2;
	void	*t_player_l3;
	void	*t_player_l4;
	void	*t_player_l5;
	void	*t_player_r2;
	void	*t_player_r3;
	void	*t_player_r4;
	void	*t_player_r5;
	void	*t_player_u2;
	void	*t_player_u3;
	void	*t_player_u4;
	void	*t_player_u5;
}				t_player;

typedef struct s_err
{
	int	e_map_no_walls;
	int	e_map_forbidden_chars;
	int	e_map_no_player;
	int	e_map_no_exit;
	int	e_map_no_collectible;
	int	e_map_diff_row_len;
}				t_err;

typedef struct s_map
{
	int		i;
	int		j;
	char	**map;
	int		zero;
	int		one;
	int		coin;
	int		p;
	int		e;
	int		exit;
	int		rows;
	int		len;
}				t_map;

typedef struct s_data
{
	struct s_map	map;
	struct s_err	err;
	struct s_player	p;
	struct s_enemy	e;
	struct s_coin	c;
	int				i;
	int				j;
	void			*mlx;
	void			*win;
	char			*addr;
	void			*t_floor;
	void			*t_wall;
	void			*t_c_exit;
	void			*t_o_exit;
	void			*t_you_loose;
	void			*t_you_win;
	int				moves;
	char			vector;
	int				f_loose;
	int				f_win;
	char			*file_name;
	int				r;
}				t_data;

int		map_ber_check(char *argv);
int		buttons_hook(int key, t_data *g);
void	render_frame(t_data *img);
void	read_xpm(t_data *g);
void	coin_animation(t_data *img);
void	put_player(t_data *g);
void	player_animation(t_data *g);
void	player_animation_d(t_data *g);
void	player_animation_l(t_data *g);
void	player_animation_r(t_data *g);
void	player_animation_u(t_data *g);
void	put_enemys(t_data *g);
void	enemy_animation(t_data *g);
void	move_enemy(t_data *g);
void	check_map_rules_part(t_data *img);
int		check_map_rules(t_data *img);
void	map_init(t_data *g);
void	err_init(t_data *img);
int		err_print(t_data *g);
int		close_win(t_data *g);
void	start(t_data *g);
int		buttons_hook(int key, t_data *g);
void	create_map(t_data *g);
void	game_moves_to_window(t_data *g);

# define WALL		"textures/wall.xpm"
# define FLOOR		"textures/floor.xpm"

# define MONEY1		"textures/money1.xpm"
# define MONEY2		"textures/money2.xpm"
# define MONEY3		"textures/money3.xpm"
# define MONEY4		"textures/money4.xpm"
# define MONEY5		"textures/money5.xpm"
# define MONEY6		"textures/money6.xpm"
# define MONEY7		"textures/money7.xpm"

# define C_EXIT		"textures/close_exit.xpm"
# define O_EXIT		"textures/open_exit.xpm"

# define U_LOOSE	"textures/you_loose.xpm"
# define U_WIN		"textures/you_win.xpm"

# define PLAYER_D1	"textures/player_1_1.xpm"
# define PLAYER_D2	"textures/player_1_2.xpm"
# define PLAYER_D3	"textures/player_1_3.xpm"
# define PLAYER_D4	"textures/player_1_4.xpm"
# define PLAYER_D5	"textures/player_1_5.xpm"

# define PLAYER_L2	"textures/player_2_2.xpm"
# define PLAYER_L3	"textures/player_2_3.xpm"
# define PLAYER_L4	"textures/player_2_4.xpm"
# define PLAYER_L5	"textures/player_2_5.xpm"

# define PLAYER_U2	"textures/player_3_2.xpm"
# define PLAYER_U3	"textures/player_3_3.xpm"
# define PLAYER_U4	"textures/player_3_4.xpm"
# define PLAYER_U5	"textures/player_3_5.xpm"

# define PLAYER_R2	"textures/player_4_2.xpm"
# define PLAYER_R3	"textures/player_4_3.xpm"
# define PLAYER_R4	"textures/player_4_4.xpm"
# define PLAYER_R5	"textures/player_4_5.xpm"

# define ENEMY1		"textures/enemy_1_1.xpm"
# define ENEMY2		"textures/enemy_1_2.xpm"
# define ENEMY3		"textures/enemy_1_3.xpm"
# define ENEMY4		"textures/enemy_1_4.xpm"
# define ENEMY5		"textures/enemy_1_5.xpm"
# define ENEMY6		"textures/enemy_1_6.xpm"

#endif
