/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/20 10:37:52 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int					get_next_line(const int fd, char **line)
{
	int 			ret;
	char 			*save;
	char			buf[BUFF_SIZE + 1];
	static char		*tmp;
	int 			i;

	i = 0;
	save = NULL;
	if (tmp != NULL)
	{
		save = ft_strdup(&tmp[1]);
		tmp = NULL;
	}
	if (save == NULL)
		save = (char *)malloc(sizeof(char));
	printf("\x1b[33mSave 28 = \t%s\n\x1b[0m", save);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (ft_strchr(save, '\n') != NULL) 
		{
			tmp = ft_strchr(save, '\n');
			printf("\x1b[31mTmp 38 =\x1b[0m");
			printf("\x1b[31m%s\x1b[0m\n", tmp);
			while (save[i])
			{
				if (save[i] == '\n')
					save[i] = '\0';
				i++;
			}
			printf("\x1b[33mSave 43 = \t%s\n\x1b[0m", save);
			*line = save;
			return (1);
		}
	}
	*line = save;
	if (ret == -1)
		return (-1);
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
		while (i < 6)
		{
			printf("-------------TEST n %i-------------\n", i + 1);
			get_next_line(fd, &line);
			printf("\x1b[32m%s\n\x1b[0m", line);
			ft_putchar('\n');
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