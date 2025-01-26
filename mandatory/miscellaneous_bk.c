/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_bk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:52 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 17:59:06 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	click(t_list *no)
{
	cleanup(no);
	exit (0);
}

void	print_and_exit(void)
{
	ft_printf("Error : Map path not found !\n");
	exit(0);
}

void	won_and_ext(t_list *no)
{
	ft_printf("You won !\n");
	cleanup(no);
	exit(0);
}

void	images_protection(t_list *no)
{
	ft_printf("Error : Images path not found !");
	cleanup(no);
	exit (0);
}

void	change_collectible(t_list *no)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (no->map[y])
	{
		while (no->map[y][x] != '\0')
		{
			if (no->map[y][x] == 'C')
			{
				mlx_put_image_to_window(no->mlx, no->win,
					no->floor, x * 64, y * 64);
				mlx_put_image_to_window(no->mlx, no->win,
					no->coll2, x * 64, y * 64);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
