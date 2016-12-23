/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/23 10:59:38 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		checkendofline(char **save, char **line)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	if (*save)
		if (ft_strchr(*save, '\n') != NULL)
		{
			tmp = ft_strchr(*save, '\n');
			tmp[0] = '\0';
			while (save[i])
			{
				if (*save[i] == '\n')
					*save[i] = '\0';
				i++;
			}
			if (!(*line = ft_strdup(*save)))
				return (0);
			if (!(*save = ft_strdup(&tmp[1])))
				return (0);
			return (1);
		}
	return (0);
}

static int		whileread(const int fd, char *buf, char **save, char **line)
{
	int			ret;
	char		*ptr;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		ptr = ft_strjoin(*save, buf);
		if (!ptr)
			return (-1);
		free(*save);
		*save = ptr;
		if (checkendofline(save, line))
		{
			free(ptr);
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*save;

	if (checkendofline(&save, line))
		return (1);
	if (!save)
		save = ft_strnew(1);
	if (whileread(fd, buf, &save, line) > 0)
		return (1);
	else if (whileread(fd, buf, &save, line) < 0)
		return (-1);
	if (save)
	{
		*line = ft_strdup(save);
		if (ft_strlen(save) == 0)
			return (0);
		save = NULL;
		return (1);
	}
	return (0);
}
