/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:28:21 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 18:30:08 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_extension(char *map)
{
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) == 0)
		return (1);
	return (ft_printf("Error : Map must end with (.ber) extension !\n"), 0);
}

int	ft_count_size_y(char *str)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			y++;
		x++;
	}
	return (y);
}

int	ft_count_size_x(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	return (x);
}
