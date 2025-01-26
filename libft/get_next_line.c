/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:23:05 by ilmahjou          #+#    #+#             */
/*   Updated: 2025/01/26 19:13:20 by ilmahjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_file(int fd, char *buffer)
{
	char	*buff;
	ssize_t	byte_read;
	char	*temp;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (free(buff), NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buff), free(buffer), NULL);
		buff[byte_read] = '\0';
		temp = buffer;
		buffer = ft_strjoin(buffer, buff);
		if (!buffer)
			return (free(buff), free(temp), NULL);
		free(temp);
	}
	return (free(buff), buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[0])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_store(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_store(buffer);
	return (line);
}

/* char *get_next_line(int fd)
{
    static char *buffer;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = ft_read_file(fd, buffer);
    if (!buffer)
        return (NULL);

    line = ft_extract_line(buffer);

    // Clear the buffer if the end of the file is reached
    if (!ft_strchr(buffer, '\n'))
    {
        free(buffer);
        buffer = NULL;
    }
    else
    {
        buffer = ft_store(buffer);
    }

    return (line);
} */

/* int main(void)
{
	int fd = open("file1.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
} */
