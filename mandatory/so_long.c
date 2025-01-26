/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:39 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 18:45:14 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_map(t_list *no)
{
	if (no->mapone != NULL
		&& ft_rectangular(no) != 0
		&& ft_closed_map_up_left(no) == 1
		&& ft_detect_imposter(no) != 0
		&& ft_missing_exit(no) != 0
		&& ft_missing_player(no) != 0
		&& ft_missing_collectibles_floor(no) != 0
		&& ft_closed_map_down_right(no) == 1
		&& ft_split_map(no) != 0)
		return (1);
	return (0);
}

static void	initialize_game_and_validate(char *map, t_list *no)
{
	no->mapone = ft_read_map(map);
	if (validate_map(no))
	{
		free(no->mapone);
		ft_scan(map);
	}
	else
	{
		free(no->mapone);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	no;

	if (argc == 2)
	{
		initialize_game_and_validate(argv[1], &no);
	}
	else
	{
		ft_printf("Error: Map path is missing!\n");
		exit(0);
	}
	return (0);
}
