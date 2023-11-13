/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:34:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/13 11:23:40 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		x;
	int		fd;
	char	*str;

	x = 1;
	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("len:%ld %d:%s", strlen(str), x, str);
		free(str);
		str = get_next_line(fd);
		x++;
	}
	printf("len:%ld %d:%s", strlen(str), x, str);
	free(str);
	close(fd);
	return (0);
}
