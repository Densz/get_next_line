/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:23:08 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/15 18:09:16 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd/*, char **line*/)
{
	int 			ret;
//	static char 	*save;
//	size_t 			i;
	char 			buf[BUFF_SIZE + 1];

//	position = 0;
	ret = 1;
	while (ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ft_putstr(buf);
/*		if (ret == 0)
		{
			ft_putstr("end of file");
			return (0);
		}
		else
		{
			buf[ret - 1] = '\0';
			while (buf[position] != '\0')
			{
				ft_putstr(buf);
				if (buf[position] == '\n')
				{
					buf[position] = '\0';
					save = ft_strjoin(save, buf);
					ft_putstr(save);
					return (1);
				}
				position++;
			}
		}
*/	}
	return (0);
}

int				main(int ac, char *av[])
{
	int 		i;
	int 		fd;
/*	char 		**line;*/


	i = 0;
	fd = 0;
	/*line = NULL;*/
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
		i = get_next_line(fd/*, line*/);
		if (close(fd) == -1)
		{
			ft_putstr("close error");
			return (1);
		}
	}
	return (0);
}

//		write(1, "b\n", 2);//		write(1, "b\n", 2);