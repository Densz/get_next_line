/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzheng <dzheng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:01:48 by dzheng            #+#    #+#             */
/*   Updated: 2016/12/23 10:04:31 by dzheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				main(int ac, char *av[])
{
	int			fd;
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		ft_putstr("ac != 2\n");
	while (i < 20)
	{
		printf("Return value = %i\n", get_next_line(fd, &line));
		printf("\x1b[32m%s\n\x1b[0m", line);
		i++;
	}
	return (0);
}
