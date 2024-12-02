/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:27 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/02 15:12:17 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *readbuffer)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	if (!line || !readbuffer)
		return (NULL);
	j = ft_strlen(line);
	while (readbuffer[i] && readbuffer[i] != '\n')
		i++;
	if (readbuffer[i] == '\n')
		i++;
	size = i + j;
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (free(line), NULL);
	ft_memcpy(str, line, j);
	i = 0;
	while (readbuffer[i] && readbuffer[i] != '\n')
		str[j++] = readbuffer[i++];
	if (readbuffer[i] == '\n')
		str[j++] = readbuffer[i++];
	str[j] = '\0';
	return (free(line), str);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	if (dest == src)
		return (dest);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
