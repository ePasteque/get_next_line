/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:00:21 by lbattest          #+#    #+#             */
/*   Updated: 2021/11/24 19:24:10 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	len = ft_strlen(s1);
	str = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (++j < len)
		str[j] = s1[j];
	while (s2 && s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strndup(char *s1, char c)
{
	int		i;
	int		len;
	char	*array_ptr;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] != c)
		i++;
	if (i < len && c != '\0')
		len = i + 1;
	array_ptr = malloc((len + 1) * sizeof(char));
	if (!array_ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array_ptr[i] = s1[i];
		i++;
	}
	array_ptr[i] = '\0';
	return (array_ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (len > i && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
