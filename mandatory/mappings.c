/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:27 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 16:26:35 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

int	ft_check_map_extension(char *map)
{
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) == 0)
		return (1);
	return (ft_printf("Error : Map must end with (.ber) extension !\n"), 0);
}

static char	*read_file_content(int fd)
{
	char	*stash;
	char	*line;
	char	*new_stash;

	stash = malloc(1);
	if (!stash)
		return (NULL);
	stash[0] = '\0';
	while ((line = get_next_line(fd)) != NULL)
	{
		new_stash = ft_strjoin(stash, line);
		free(line);
		if (!new_stash)
			return (free(stash), NULL);
		free(stash);
		stash = new_stash;
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

	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_and_exit();
	stash = read_file_content(fd); // Read file content
	close(fd);

	if (!stash || stash[0] == '\0')
	{
		ft_printf("Error: Map is empty\n");
		free(stash);
		return (NULL);
	}
	trim_trailing_newline(stash); // Trim the trailing newline

	return (stash);
}
