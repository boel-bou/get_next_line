/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boel-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:22:02 by boel-bou          #+#    #+#             */
/*   Updated: 2023/11/30 22:22:56 by boel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char i)
{
	int	j;

	j = 0;
	if (!str)
		return (NULL);
	while (str[j] && str[j] != i)
		j++;
	if (str[j] == i)
		return (str + j);
	return (NULL);
}

void	ft_bzero(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		str[i++] = '\0';
}

char	*ft_calloc(int count, int size)
{
	char	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	char	*join;
	int		j;
	int		l;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	j = 0;
	l = ft_strlen(s1) + ft_strlen(s2);
	join = ft_calloc(l + 1, 1);
	if (!join)
		return (NULL);
	l = 0;
	while (s1[l])
	{
		join[l] = s1[l];
		l++;
	}
	while (s2[j])
		join[l++] = s2[j++];
	free(s1);
	return (join);
}
