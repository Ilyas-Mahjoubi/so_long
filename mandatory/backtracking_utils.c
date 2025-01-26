/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:27:32 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 18:44:23 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
