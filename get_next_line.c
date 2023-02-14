/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:18:19 by mayan             #+#    #+#             */
/*   Updated: 2023/02/14 20:54:23 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*buff;
	int		rd_count;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_count = 1;
	while (rd_count != 0 && !ft_strchr(buffer, '\n'))
	{
		rd_count = read(fd, buff, BUFFER_SIZE);
		if (rd_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_count] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE > 2147483646 || BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_remaining(buffer);
	return (line);
}
