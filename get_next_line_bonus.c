/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:11:14 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/18 18:26:15 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*j_free(char *str)
{
	free(str);
	return (NULL);
}

char	*get_cache(char *cache)
{
	char	*new;
	int		length;
	int		i;

	if (indexof(cache, '\n') < 0)
		return (j_free(cache));
	i = indexof(cache, '\n') + 1;
	length = 0;
	while (cache[i + length])
		length++;
	new = j_substr(cache, i, length);
	j_free(cache);
	return (new);
}

char	*get_txt(int fd, char *cache)
{
	char	*buff;
	int		read_status;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (j_free(cache));
	read_status = BUFFER_SIZE;
	while (indexof(cache, '\n') == -1 && read_status == BUFFER_SIZE)
	{
		read_status = read(fd, buff, BUFFER_SIZE);
		if (read_status <= 0)
		{
			j_free(buff);
			if (read_status == 0)
				return (cache);
			return (j_free(cache));
		}
		buff[read_status] = '\0';
		cache = j_strjoin(cache, buff);
	}
	j_free (buff);
	return (cache);
}

char	*get_one_line(char *cache)
{
	size_t	length;

	length = 0;
	if (cache == NULL || !cache[0])
		return (NULL);
	while (cache[length] != '\n' && cache[length] != '\0')
		length++;
	if (cache[length] == '\n')
		length++;
	return (j_substr(cache, 0, length));
}

char	*get_next_line(int fd)
{
	static char	*cache[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (cache[fd] == NULL)
	{
		cache[fd] = malloc(sizeof(char));
		if (!cache[fd])
			return (NULL);
		cache[fd][0] = '\0';
	}
	cache[fd] = get_txt(fd, cache[fd]);
	line = get_one_line(cache[fd]);
	cache[fd] = get_cache(cache[fd]);
	return (line);
}
