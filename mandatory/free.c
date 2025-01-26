/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:00:50 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:25:21 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_map_and_textures(t_list *no)
{
	int	i;

	i = -1;
	if (no->map)
	{
		while (no->map[++i])
			free(no->map[i]);
		free(no->map);
	}
	if (no->floor)
		mlx_destroy_image(no->mlx, no->floor);
	if (no->play)
		mlx_destroy_image(no->mlx, no->play);
	if (no->plale)
		mlx_destroy_image(no->mlx, no->plale);
	if (no->wall)
		mlx_destroy_image(no->mlx, no->wall);
	if (no->exit)
		mlx_destroy_image(no->mlx, no->exit);
	if (no->coll1)
		mlx_destroy_image(no->mlx, no->coll1);
	if (no->coll2)
		mlx_destroy_image(no->mlx, no->coll2);
	if (no->mapone)
		free(no->mapone);
}

void	cleanup_display_and_window(t_list *no)
{
	if (no->win)
		mlx_destroy_window(no->mlx, no->win);
	if (no->mlx)
		mlx_destroy_display(no->mlx);
	if (no->mlx)
		free(no->mlx);
}

void	cleanup(t_list *no)
{
	cleanup_map_and_textures(no);
	cleanup_display_and_window(no);
}
