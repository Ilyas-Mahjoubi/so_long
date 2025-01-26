/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:27 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 20:15:04 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file_content(int fd)
{
	char	*stash;
	char	*line;
	char	*new_stash;

	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	line = get_next_line(fd);
	while (line != NULL)
	{
		new_stash = ft_strjoin(stash, line);
		free(line);
		if (!new_stash)
			return (free(stash), NULL);
		free(stash);
		stash = new_stash;
		line = get_next_line(fd);
	}
	return (stash);
}

static void	trim_trailing_newline(char *map) // Remove trailing newline
{
	int	len;

	len = ft_strlen(map);
	if (len > 0 && map[len - 1] == '\n')
		map[len - 1] = '\0';
}

char	*ft_read_map(char *map)
{
	char	*stash;
	int		fd;
	int		check;

	check = ft_check_map_extension(map);
	if (check == 0)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_and_exit();
	stash = read_file_content(fd);
	close(fd);
	if (!stash || stash[0] == '\0')
	{
		ft_printf("Error: Map is empty\n");
		free(stash);
		return (NULL);
	}
	trim_trailing_newline(stash);
	return (stash);
}
