/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:37:31 by rdragan           #+#    #+#             */
/*   Updated: 2022/12/15 16:09:06 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
size_t	len(char *s);
char	*j_strchr(char *s, char c);
char	*j_strjoin(char *s1, char *s2);
char	*j_substr(char *s1, size_t start, size_t end);
int		indexof(char *s1, char c);
#endif