/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 11:56:05 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*l;
	static t_buf	buf;

	l = "\0";
	buf.len = read(fd, buf.content, BUFFER_SIZE);
	if (buf.len <= 0)
		return (NULL);
	buf.cursor = find_end_line(buf.content, buf.cursor);
	printf("%zu\n", buf.cursor);
	while (buf.cursor >= 0)
	{
		l = strcaldupcat(l, buf.content, ft_strlen(l), buf.cursor);
		if (!l)
			return (free_and_exit(l));
		buf.len = read(fd, buf.content, BUFFER_SIZE);
		if (buf.len >= 0)
			return (free_and_exit(l));
		buf.cursor = find_end_line(buf.content, buf.cursor);
	}
	l = strcaldupcat(l, buf.content, ft_strlen(l), buf.cursor);
	if (!l)
		return (free_and_exit(l));
	return (l);
}
