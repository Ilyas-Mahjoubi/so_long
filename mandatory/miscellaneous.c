/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:00 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 18:44:02 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assign_pictures(t_list *no)
{
	no->wall = mlx_xpm_file_to_image(no->mlx, "./imgs/w.xpm", &no->xu, &no->yu);
	no->floor = mlx_xpm_file_to_image(no->mlx, "./imgs/0.xpm",
			&no->xu, &no->yu);
	no->play = mlx_xpm_file_to_image(no->mlx, "./imgs/P.xpm", &no->xu, &no->yu);
	no->plale = mlx_xpm_file_to_image(no->mlx, "./imgs/P.xpm",
			&no->xu, &no->yu);
	no->coll1 = mlx_xpm_file_to_image(no->mlx, "./imgs/call1.xpm",
			&no->xu, &no->yu);
	no->coll2 = mlx_xpm_file_to_image(no->mlx, "./imgs/coll2.xpm",
			&no->xu, &no->yu);
	no->exit = mlx_xpm_file_to_image(no->mlx, "./imgs/E.xpm", &no->xu, &no->yu);
	if (!no->floor || !no->wall || !no->coll1
		|| !no->coll2 || !no->exit || !no->plale)
		images_protection(no);
}

void	ft_assign(t_list no)
{
	int		i;

	no.x_as = 0;
	i = 0;
	no.y_as = 0;
	while (no.mapone[i] != '\0')
	{
		if (no.mapone[i] == '0')
			mlx_put_image_to_window(no.mlx, no.win, no.floor, no.x_as, no.y_as);
		else if (no.mapone[i] == '1')
			mlx_put_image_to_window(no.mlx, no.win, no.wall, no.x_as, no.y_as);
		else if (no.mapone[i] == 'P')
			mlx_put_image_to_window(no.mlx, no.win, no.play, no.x_as, no.y_as);
		else if (no.mapone[i] == 'C')
			mlx_put_image_to_window(no.mlx, no.win, no.coll1, no.x_as, no.y_as);
		else if (no.mapone[i] == 'E')
			mlx_put_image_to_window(no.mlx, no.win, no.exit, no.x_as, no.y_as);
		no.x_as += 64;
		if (no.mapone[i] == '\n')
		{
			no.y_as += 64;
			no.x_as = 0;
		}
		i++;
	}
}

void	ft_scan(char *map)
{
	t_list	no;

	no = (t_list){0};
	no.mapone = ft_read_map(map);
	no.x_win = ft_count_size_x(no.mapone);
	no.y_win = ft_count_size_y(no.mapone);
	no.mlx = mlx_init();
	no.win = mlx_new_window(no.mlx, no.x_win * 64, no.y_win * 64, "so_long");
	ft_assign_pictures(&no);
	no.xp = ft_player_position_x(&no) * 64;
	no.yp = ft_player_position_y(&no) * 64;
	ft_assign(no);
	ft_printf("Player Moves : %d\n", no.moves = 0);
	no.map = ft_split(no.mapone, '\n');
	no.collectibles = ft_count_collectibles(&no);
	mlx_hook(no.win, 2, 1L << 0, key, &no);
	mlx_hook(no.win, 17, 1L << 0, click, &no);
	mlx_loop(no.mlx);
}
