/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 18:11:20 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/18 18:26:40 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define FD_MAX 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*j_free(char *str);
char	*get_next_line(int fd);
char	*get_cache(char *cache);
char	*get_one_line(char *cache);
char	*get_txt(int fd, char *cache);
size_t	len(char *s);
char	*j_strjoin(char *s1, char *s2);
char	*j_substr(char *s1, size_t start, size_t end);
int		indexof(char *s1, char c);

#endif