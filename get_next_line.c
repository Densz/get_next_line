/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/20 17:45:18 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int 				checkendofline(char **save, char **line)
{
	char 	*tmp;
	int 	i;

	i = 0;
	tmp = NULL;
	if (*save)
	{	
		if (ft_strchr(*save, '\n') != NULL) 
		{
			tmp = ft_strchr(*save, '\n');
			*tmp = '\0';
			while (save[i])
			{
				if (*save[i] == '\n')
					*save[i] = '\0';
				i++;
			}
			*line = ft_strdup(*save);
			*save = ft_strdup(&tmp[1]);
			tmp = NULL;
			free (tmp);
			return (1);
		}
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int 			ret;
	char			buf[BUFF_SIZE + 1];
	static char		*save;

	if (checkendofline(&save, line))
		return (1);
	if (!save)
		save = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (fd == -1)
			return (-1);
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (checkendofline(&save, line))
			return (1);
	}
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

int				main(int ac, char *av[])
{
	int 		fd;
	char		*line;
	int 		i;

	i = 0;
	line = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: get next line input\n");
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("open error");
			return (1);
		}
		while (i < 20)
		{
			get_next_line(fd, &line);
			printf("\x1b[32m%s\n\x1b[0m", line);
			i++;
		}
		if (close(fd) == -1)
		{
			ft_putstr("close error");
			return (1);
		}
	}
	return (0);
}
