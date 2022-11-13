/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OUShassan <OUShassan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:52:15 by ooussaad          #+#    #+#             */
/*   Updated: 2022/11/13 23:49:51 by OUShassan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_read(int fd, char *str)
{
	char	*buff;
	int		byte;

	byte = 1;
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[byte] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*first_line(char *buffer)
{
	char	*temp;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*new_line(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(line)-i + 1));
	if (!str)
	{
		return (NULL);
	}
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*my_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	my_line = to_read(fd, my_line);
	if (!my_line)
		return (NULL);
	line = first_line(my_line);
	my_line = new_line(my_line);
	return (line);
}
