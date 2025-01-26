/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:27:47 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:25:05 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_position_x(t_list *no)
{
	char	*str;
	int		i;
	int		x;

	str = no->mapone;
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			x = -1;
		i++;
		x++;
		if (str[i] == 'P')
			break ;
	}
	return (x);
}

int	ft_player_position_y(t_list *no)
{
	char	*str;
	int		i;
	int		y;

	str = no->mapone;
	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
		if (str[i] == 'P')
			break ;
	}
	return (y);
}

int	ft_count_collectibles(t_list *no)
{
	char	*str;
	int		i;
	int		collectibles;

	str = no->mapone;
	i = 0;
	collectibles = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			collectibles++;
		i++;
	}
	return (collectibles);
}

void	ft_initialize_game(t_list *no)
{
	no->total_collectibles = ft_count_collectibles(no);
	no->collectibles_collected = 0;
}
static int check_and_collect(char **map, int x, int y, t_list *no)
{
	if (map[y][x] == 'C')
	{
		no->collectibles_collected++;
		map[y][x] = '1';
	}
	if (map[y][x] == 'E')
	{
		if (no->collectibles_collected == no->total_collectibles)
			return 1;
		return 0;
	}
	return -1;
}

static int backtrack_helper(char **map, int x, int y, t_list *no)
{
	char temp;

	if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' || map[y][x] == '1')
		return 0;
	if (check_and_collect(map, x, y, no) == 1)
		return 1;
	if (check_and_collect(map, x, y, no) == 0)
		return 0;
	temp = map[y][x];
	map[y][x] = '1';
	if (backtrack_helper(map, x, y - 1, no))
		return 1;
	if (backtrack_helper(map, x, y + 1, no))
		return 1;
	if (backtrack_helper(map, x + 1, y, no))
		return 1;
	if (backtrack_helper(map, x - 1, y, no))
		return 1;
	if (temp != 'C')
		map[y][x] = temp;
	return 0;
}

int ft_backtracking(char **map, int x, int y, t_list *no)
{
	return backtrack_helper(map, x, y, no);
}

int	ft_split_map(t_list *no)
{
	char	**new_map;
	int		x;
	int		result;
	int		y;
	int		i;

	new_map = ft_split(no->mapone, '\n');
	if (!new_map)
		return (0);
	ft_initialize_game(no);
	x = ft_player_position_x(no);
	y = ft_player_position_y(no);
	no->collectibles_collected = 0;
	result = ft_backtracking(new_map, x, y, no);
	i = -1;
	while (new_map[++i])
		free(new_map[i]);
	free(new_map);
	if (result == 0)
		return (ft_printf("Player cannot win the map.\n"), 0);
	return (1);
}
