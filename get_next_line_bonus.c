/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:59:47 by lbattest          #+#    #+#             */
/*   Updated: 2021/11/25 17:28:17 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_nl(char **str)
{
	char	*save;
	char	*tmp;

	tmp = ft_strndup(*str, '\n');
	save = ft_strndup(ft_strchr(*str, '\n') + 1, '\0');
	free(*str);
	*str = save;
	return (tmp);
}

static char	*scotch(char *str)
{
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	int			i;
	char		buf[BUFFER_SIZE + 1];
	static char	*str = NULL;
	char		*tmp;

	tmp = 0;
	i = 1;
	if (read(fd, buf, 0) < 0)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (0);
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (0);
	}
	if (ft_strchr(str, '\n'))
		return (extract_nl(&str));
	if (str && str[0])
		tmp = ft_strndup(str, '\0');
	str = scotch(str);
	return (tmp);
}
