/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:34:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/10 10:06:35 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	int		x;
	char	*str;

	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	str = "\0";
	x = 1;
	while (x)
	{
		str = get_next_line(fd);
		if (str)
		{
			printf("%s", str);
			x++;
		}
		else
			x = 0;
		free(str);
	}
	close(fd);
	return (0);
}
