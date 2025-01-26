/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:27:56 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:25:13 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_detect_imposter(t_list *no)
{
	char	*str;
	int		i;
	int		imposter;

	str = no->mapone;
	i = 0;
	imposter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '0' || str[i] == '1' || str[i] == 'P'
			|| str[i] == 'E' || str[i] == 'C')
			i++;
		else
		{
			imposter++;
			i++;
		}
	}
	if (imposter != 0)
		return (ft_printf("Error : A diff compo in the map detected !\n"), 0);
	return (1);
}

int	ft_missing_player(t_list *no)
{
	char	*str;
	int		i;
	int		player;

	str = no->mapone;
	i = 0;
	player = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			player++;
		i++;
	}
	if (player == 1)
		return (1);
	return (ft_printf("Error : Missing or multiple P in the map !\n"), 0);
}

int	ft_missing_exit(t_list *no)
{
	char	*str;
	int		i;
	int		exit;

	str = no->mapone;
	i = 0;
	exit = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E')
			exit++;
		i++;
	}
	if (exit == 1)
		return (1);
	return (ft_printf("Error : Missing or multiple exits in the map !\n"), 0);
}

int	ft_missing_collectibles_floor(t_list *no)
{
	char	*str;
	int		i;
	int		collectible;
	int		floor;

	str = no->mapone;
	i = 0;
	collectible = 0;
	floor = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			collectible++;
		else if (str[i] == '0')
			floor++;
		i++;
	}
	if (collectible == 0 || floor == 0)
		return (ft_printf("Error : Missing C or floor in the map !\n"), 0);
	return (1);
}
