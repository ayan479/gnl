/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:18:19 by mayan             #+#    #+#             */
/*   Updated: 2023/02/19 20:24:43 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*buff;
	char	*temp;
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
		temp = ft_strjoin(buffer, buff);
		free(buffer);
		buffer = temp;
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
	buffer = ft_next(buffer);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;

// 	fd1 = open("text.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 8)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line[%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }
