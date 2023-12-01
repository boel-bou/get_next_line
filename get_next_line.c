/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:50:42 by boel-bou          #+#    #+#             */
/*   Updated: 2023/11/30 17:50:32 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	int		l;
	char	*next_line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	l = ft_strlen(buffer);
	next_line = ft_calloc(l - i + 1, 1);
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
	line = ft_calloc(i + 2, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*get_buffer(int fd, char *str)
{
	int		i;
	char	*buffer;

	buffer = ft_calloc(BUFFER_MAX + 1, 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i != 0 && !(ft_strchr(buffer, '\n')))
	{
		i = read(fd, buffer, BUFFER_MAX);
		if (i == -1)
		{
			free(buffer);
			return (str);
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

	if (fd < 0 || BUFFER_MAX <= 0)
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
