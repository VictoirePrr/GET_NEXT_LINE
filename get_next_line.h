/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:31:55 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/02 14:58:04 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *line, char *readbuffer);
char	*ft_substr(char *s, unsigned int start, size_t len);

size_t	ft_strlen(char *str);

void	ft_bzero(void *s, size_t n);
void	ft_update(char *readbuffer);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
