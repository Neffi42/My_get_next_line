/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:34:37 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/10 17:19:08 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"
#include "get_next_line_bonus.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	if (ac == 1)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	close(fd);
	return (0);
}
