/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:27 by vicperri          #+#    #+#             */
/*   Updated: 2024/12/02 15:11:52 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_update(char *readbuffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (readbuffer[i] && readbuffer[i] != '\n')
		i++;
	if (readbuffer[i] == '\n')
		i++;
	while (readbuffer[i])
	{
		readbuffer[j] = readbuffer[i];
		i++;
		j++;
	}
	readbuffer[j] = '\0';
}

char	*ft_strchr(const char *s, int c)
{
	char			*s1;
	unsigned char	c1;
	int				i;

	s1 = (char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (s1[i])
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	if (c1 == '\0')
		return (&s1[i]);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	i = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	if (s1[len] == '\n')
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	readbuffer[BUFFER_SIZE + 1] = {0};
	char		*line;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	line = ft_strdup(readbuffer);
	if (!line)
		return (NULL);
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, readbuffer, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_bzero(readbuffer, BUFFER_SIZE), free(line), NULL);
		readbuffer[bytes] = '\0';
		line = ft_strjoin(line, readbuffer);
		if (!line)
			return (NULL);
	}
	if (!line[0] && bytes == 0)
		return (free(line), NULL);
	ft_update(readbuffer);
	return (line);
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int fd = open("hello.txt", O_RDONLY);
// 	char *line;

// 	if (fd < 0)
// 		return (1);

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }