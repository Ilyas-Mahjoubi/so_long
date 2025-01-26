/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:29:24 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:27:00 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_row_length(char *str, int *i)
{
	int first_row_length;

	first_row_length = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		first_row_length++;
		(*i)++;
	}
	return (first_row_length);
}

int	ft_rectangular(t_list *no)
{
	char	*str;
	int		first_row_length;
	int		current_row_length;
	int		i;

	str = no->mapone;
	i = 0;
	first_row_length = check_first_row_length(str, &i); // Get the first row length
	i++; // Skip the newline character
	while (str[i] != '\0')
	{
		current_row_length = 0;
		current_row_length = check_first_row_length(str, &i); // Get current row length
		if (current_row_length != first_row_length)
			return (ft_printf("Error : Map is not rectangular !\n"), 0);
		if (str[i] == '\n')
			i++;
	}
	return (1);
}



/* int	check_row_length(char *str, int *i)
{
	int	current_row_length;

	current_row_length = 0;
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		current_row_length++;
		(*i)++;
	}
	return (current_row_length);
}

int	ft_rectangular(t_list *no)
{
	char	*str;
	int		first_row_length;
	int		current_row_length;
	int		i;

	str = no->mapone;
	first_row_length = check_row_length(str, &i);
	i++;
	while (str[i] != '\0')
	{
		current_row_length = check_row_length(str, &i);
		if (current_row_length != first_row_length)
			return (ft_printf("Error : Map is not rectangular !\n"), 0);
		if (str[i] == '\n')
			i++;
	}
	return (1);
} */

int	ft_closed_map_up_left(t_list *no)
{
	char	*str;
	int		i;

	str = no->mapone;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != '1')
			return (ft_printf("Error: T map is not closed by w!\n"), 0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] != '1' && str[i] != '\0')
				return (ft_printf("Error: L of map is not closed by w\n"), 0);
		}
		else
			i++;
	}
	return (1);
}

int	ft_closed_map_down_right(t_list *no)
{
	char	*str;
	int		i;
	int		row_start;

	str = no->mapone;
	i = 0;
	while (str[i] != '\0')
	{
		row_start = i;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i - 1] != '1')
			return (ft_printf("Error: B or R m is not c by walls!\n"), 0);
		if (str[i] == '\n')
			i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i] != '\n' && i >= 0)
	{
		if (str[i] != '1')
			return (ft_printf("Error: B or R of m is not c by walls!\n"), 0);
		i--;
	}
	return (1);
}
