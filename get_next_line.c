/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/19 14:39:44 by dzheng           ###   ########.fr       */
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
		save = &tmp[1];
	if (save == NULL)
		save = (char *)malloc(sizeof(char));
	while ((ret = read(fd, buf, BUFF_SIZE))) //PENDANT LA LECTURE
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf); //LINK BUF AND SAVE -- SAVE || BUF
		if (ft_strchr(save, '\n') != NULL) //SAVE = /n....
		{
			tmp = ft_strchr(save, '\n'); //TMP = \n to the rest of the text
			while (save[i])
			{
				if (save[i] == '\n')
					save[i] = '\0';
				i++;
			}
			*line = save;
			return (1);
		}
	}
	if (ret == -1)
		return (-1);
	return (0);
}

int				main(int ac, char *av[])
{
	int 		fd;
	char		*line;

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
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		if (close(fd) == -1)
		{
			ft_putstr("close error");
			return (1);
		}
	}
	return (0);
}