/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:50 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:27:19 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*wall;
	void	*play;
	void	*plale;
	void	*coll1;
	void	*coll2;
	void	*floor;
	void	*exit;
	char	**map;
	int		x_win;
	int		y_win;
	int		collectibles;
	int		moves;
	int		yp;
	int		xp;
	int		x_move;
	int		y_move;
	int		x_as;
	int		y_as;
	char	*mapone;
	int		xu;
	int		yu;
	int		collectibles_collected;
	int		total_collectibles;
}	t_list;

char	**ft_split(char *s, char c);
	/*backtracking*/
int	ft_player_position_x(t_list *no);
int	ft_player_position_y(t_list *no);
void	ft_initialize_game(t_list *no);
int	ft_backtracking(char **map, int x, int y, t_list *no);
int	ft_split_map(t_list *no);
	/*free*/
void	cleanup_map_and_textures(t_list *no);
void	cleanup_display_and_window(t_list *no);
void	cleanup(t_list *no);
	/*mapping*/
int	ft_check_path(char *map);
int	ft_check_map_extension(char *map);
//static void trim_trailing_newline(char *map);
char *ft_read_map(char *map);
//char	*read_lines(int fd);
char	*ft_read_map(char *map);
	/*MAPPING2*/
int	ft_count_size_x(char *str);
int	ft_count_size_y(char *str);
	/*miscellaneous_bk.c*/
int	click(t_list *no);
void	print_and_exit(void);
void	won_and_ext(t_list *no);
void	images_protection(t_list *no);
void	change_collectible(t_list *no);
	/*miscellaneous.c*/
void	ft_assign_pictures(t_list *no);
void	ft_assign(t_list no);
void	ft_scan(char *map);
	/*movements.c*/
void	key_right(t_list *no);
void	key_left(t_list *no);
void	key_down(t_list *no);
void	key_up(t_list *no);
int	key(int keycode, t_list *all);
	/*parsing.c*/
//int	check_row_length(char *str, int *i);
int	ft_rectangular(t_list *no);
int	ft_closed_map_up_left(t_list *no);
int	ft_closed_map_down_right(t_list *no);
int	ft_count_collectibles(t_list *no);
	/*components.c*/
int	ft_detect_imposter(t_list *no);
int	ft_missing_player(t_list *no);
int	ft_missing_exit(t_list *no);
int	ft_missing_collectibles_floor(t_list *no);

#endif
