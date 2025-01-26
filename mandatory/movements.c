/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:09 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 17:36:11 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_right(t_list *no)
{
	no->x_move++;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext(no);
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp + 64, no->yp);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->xp += 64;
		printf("Player Moves : %d\n", ++no->moves);
		no->x_move = (no->xp / 64);
	}
}

void	key_left(t_list *no)
{
	no->x_move--;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext(no);
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->plale, no->xp - 64, no->yp);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->xp -= 64;
		printf("Player Moves : %d\n", ++no->moves);
		no->x_move = (no->xp / 64);
	}
}

void	key_down(t_list *no)
{
	no->y_move++;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext(no);
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp, no->yp + 64);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->yp += 64;
		ft_printf("Player Moves : %d\n", ++no->moves);
		no->y_move = (no->yp / 64);
	}
}

void	key_up(t_list *no)
{
	no->y_move--;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext(no);
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp, no->yp - 64);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->yp -= 64;
		printf("Player Moves : %d\n", ++no->moves);
		no->y_move = (no->yp / 64);
	}
}

int	key(int keycode, t_list *all)
{
	all->x_move = all->xp / 64;
	all->y_move = all->yp / 64;
	if (keycode == XK_Escape)
	{
		cleanup(all);
		print_and_exit();
	}
	if (keycode == XK_w || keycode == XK_Up)
		key_up(all);
	if (keycode == XK_s || keycode == XK_Down)
		key_down(all);
	if (keycode == XK_a || keycode == XK_Left)
		key_left(all);
	if (keycode == XK_d || keycode == XK_Right)
		key_right(all);
	return (0);
}

