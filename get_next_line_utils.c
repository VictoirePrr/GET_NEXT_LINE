/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:27 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/26 15:07:50 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	i = 0;
	len = (ft_strlen(s1));
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (!(dup))
		return (NULL);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *line, char *readbuffer)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (line == NULL)
		line = ft_strdup("");
	else
		free(line);
	j = 0;
	size = ft_strlen(line) + ft_strlen(readbuffer) + 1;
	str = (char *)malloc((size) * sizeof(char));
	if (!(str))
		return (NULL);
	str = ft_strcpy(str, line);
	i = ft_strlen(line);
	while (readbuffer[j])
	{
		str[i] = readbuffer[j];
		printf("Reading... str[i]: %c\n", str[i]);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	bytes;

	bytes = nmemb * size;
	res = malloc(nmemb * size);
	if (nmemb > 0 && size > SIZE_MAX / nmemb)
		return (0);
	if (!(res))
		return (0);
	ft_bzero(res, bytes);
	return (res);
}

char	*trim_read(char *readbuffer, char set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	if (!(readbuffer || set))
		return (NULL);
	while (readbuffer[start] && readbuffer[start] != set)
		start++;
	end = ft_strlen(readbuffer) - 1;
	while (end > start && readbuffer[start] != set)
		end--;
	str = ft_substr(readbuffer, start, end - start + 1);
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	while (n--)
		*s1++ = '\0';
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1 * sizeof(char));
	if (!(str))
		return (NULL);
	while (s[start] && len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
