/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:39 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/18 13:34:44 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_cache(char *cache)
{
	char	*new;
	int		length;
	int		i;

	if (indexof(cache, '\n') < 0)
	{
		free(cache);
		cache = NULL;
		return (NULL);
	}
	i = indexof(cache, '\n') + 1;
	length = 0;
	while (cache[i + length])
		length++;
	new = j_substr(cache, i, length);
	free(cache);
	cache = NULL;
	return (new);
}

char	*get_txt(int fd, char *cache)
{
	char	*buff;
	int		read_status;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_status = BUFFER_SIZE;
	while (!j_strchr(cache, '\n') && read_status == BUFFER_SIZE)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		cache = j_strjoin(cache, buff);
		if (read_status < 0)
		{
			free(cache);
			cache = NULL;
			return (NULL);
		}
	}
	free (buff);
	return (cache);
}

char	*get_line(char *cache)
{
	size_t	length;

	length = 0;
	while (cache[length] && cache[length] != '\n' && cache[length] != '\0')
		length++;
	if (cache[length] == '\n')
		length++;
	return (j_substr(cache, 0, length));
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (cache == NULL)
	{
		cache = malloc(sizeof(char));
		if (!cache)
			return (NULL);
		cache[0] = '\0';
	}
	cache = get_txt(fd, cache);
	line = get_line(cache);
	cache = get_cache(cache);
	return (line);
}
