/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:23:46 by boel-bou          #+#    #+#             */
/*   Updated: 2023/12/01 13:31:44 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_BONUS_H
# define _GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_MAX 50

char	*get_next_line(int fd);
char	*ft_calloc(int count, int size);
int	ft_strlen(char *str);
void	ft_bzero(char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char i);
char	*get_buffer(int fd, char *str);
char	*ft_line(char *buffer);
char	*next_line(char *buffer);

#endif
