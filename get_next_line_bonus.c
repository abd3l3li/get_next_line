/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:30:08 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/11 02:30:52 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_reads(int fd, char *str)
{
	char	*buf;
	int		count;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while (!ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
			return (free_buf(buf));
		buf[count] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*ft_extract_line(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dup = (char *)malloc(sizeof(char) * (i + 2));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dup[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_next_update(char *str)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free_buf(str));
	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!dup)
		return (free_buf(str));
	i++;
	j = 0;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	free(str);
	return (dup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (0);
	str[fd] = ft_reads(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_extract_line(str[fd]);
	str[fd] = ft_next_update(str[fd]);
	return (line);
}
