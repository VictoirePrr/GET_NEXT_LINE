/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicperri <vicperri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:00:27 by vicperri          #+#    #+#             */
/*   Updated: 2024/11/26 15:20:53 by vicperri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	check_read(char *readbuffer)
{
	size_t	i;

	i = 0;
	while (readbuffer[i])
	{
		if (readbuffer[i] == '\0' || readbuffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
void	keep_leftovers(char *readbuffer, char *leftover)
{
	size_t	i;

	i = 0;
	while (readbuffer[i])
	{
		if (readbuffer[i] == '\n')
			leftover = ft_strcpy(leftover, readbuffer);
		i++;
	}
}

char	*cpy_leftovers(char *leftover, char *line)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(line);
	j = 0;
	while (leftover[j])
	{
		line[i++] = leftover[j++];
	}
	line[i] = '\0';
	ft_bzero(leftover, BUFFER_SIZE); // VIDANGE DU LEFTOVER
	return (line);
}
char	*get_next_line(int fd)
{
	static char	leftover[BUFFER_SIZE] = {0};
	char		*readbuffer;
	char		*line;
	size_t		bytes;

	bytes = 1;
	line = NULL;
	readbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!(readbuffer))
		return (NULL);
	while (bytes > 0 && check_read(readbuffer) == 0)
	{
		if (leftover[0] != '\0')
			line = cpy_leftovers(leftover, line);
		bytes = read(fd, readbuffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free(readbuffer), free(line), NULL);
		printf("Reading... readbuffer[0]: %c\n", readbuffer[0]);
		readbuffer[bytes] = '\0';
		keep_leftovers(readbuffer, leftover);
		line = ft_strjoin(line, readbuffer);
		if (!line)
			return (free(readbuffer), NULL);
		readbuffer = trim_read(readbuffer, '\n');
	}
	free(readbuffer);
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	char *buffer;
	char *fileName = "hello.txt";

	int fd = open(fileName, O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}

	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s\n", buffer);
		free(buffer);
	}

	close(fd);
	return (0);
}