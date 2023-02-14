/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:18:37 by mayan             #+#    #+#             */
/*   Updated: 2023/02/14 19:27:17 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = c;
	while (*s)
	{
		if (*s == uc)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
	{
		return (NULL);
	}
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*tab;

	if (!s1 ||!s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tab = malloc(len1 + len2 + 1);
	if (!tab)
		return (NULL);
	ft_memcpy(tab, s1, len1);
	ft_memcpy(tab + len1, s2, len2 + 1);
	free(s1);
	return (tab);
}

char	*ft_getline(char *buffer)
{
	
}

char	*ft_new_left_str(char *left_str)
{
	
}

// The get_next_line function uses the ft_read function to 
// read data from the file descriptor and append it to a static string buffer.
// The static buffer variable is used to accumulate data 
// across multiple calls to get_next_line, allowing the function
// to return the lines of text read from the file descriptor
// one line at a time. The ft_getline function is used to
// extract the next line of text from the left_str string,
// and the ft_new_left_str function is used to update the left_str string
// to remove the line that was returned. The get_next_line function
// then returns the line of text extracted by ft_getline.