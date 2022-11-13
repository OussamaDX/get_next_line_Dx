/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OUShassan <OUShassan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:25:08 by ooussaad          #+#    #+#             */
/*   Updated: 2022/11/13 23:50:36 by OUShassan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned int	i;
	char			*src_char;
	char			*dest_char;

	i = 0;
	src_char = (char *)src;
	dest_char = (char *)dst;
	if (dest_char == src_char)
		return (dest_char);
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
	i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char )c)
		{
			return ((char *)s);
		}
	s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	size_t	len;
	size_t	i;

	s = NULL;
	len = ft_strlen(s1) + 1;
	i = 0;
	s = (char *)malloc (len * sizeof(char ));
	if (!s || !s1)
		return (NULL);
	ft_memcpy (s, s1, len);
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (malloc(len * (sizeof (*res)) + 1));
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = 0;
	free (s1);
	return (res);
}
