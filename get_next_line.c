/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <boel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:50:42 by boel-bou          #+#    #+#             */
/*   Updated: 2023/12/01 16:29:51 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (!next_line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_buffer(int fd, char *str)
{
	int		i;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i != 0 && !(ft_strchr(str, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = next_line(buffer);
	return (line);
}

// int	main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("lara.txt", O_RDWR | O_CREAT);
// 	if (fd < 0)
// 	{
// 		printf ("error\n");
// 		return (-1);
// 	}
// 	while (line = get_next_line(fd))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close (fd);
// }
