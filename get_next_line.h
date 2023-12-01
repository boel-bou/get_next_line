/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:39:36 by boel-bou          #+#    #+#             */
/*   Updated: 2023/11/30 22:35:51 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_MAX 50

char	*get_next_line(int fd);
char	*ft_calloc(int count, int size);
int		ft_strlen(char *str);
void	ft_bzero(char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char i);
char	*get_buffer(int fd, char *str);
char	*ft_line(char *buffer);
char	*next_line(char *buffer);

#endif
