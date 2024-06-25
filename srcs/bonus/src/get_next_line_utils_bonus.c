/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grudilda <grudilda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:41:01 by grudilda          #+#    #+#             */
/*   Updated: 2024/06/22 23:43:31 by grudilda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

char	*ft_strchr(char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *) &s[index]);
		index++;
	}
	if (s[index] == (char)c)
		return ((char *) &s[index]);
	return (NULL);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = 0;
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		index;

	index = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dup == NULL)
		return (NULL);
	while (s1[index])
	{
		dup[index] = s1[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index_s1;
	size_t	index_s2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	index_s1 = -1;
	while (s1[++index_s1])
		str[index_s1] = s1[index_s1];
	index_s2 = -1;
	while (s2[++index_s2])
		str[index_s1 + index_s2] = s2[index_s2];
	str[index_s1 + index_s2] = '\0';
	return (str);
}
