/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 18:24:13 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_buffer(t_buf *buf, int fd)
{
	if (buf->len == (ssize_t)buf->cursor)
		buf->cursor = 0;
	buf->len = read(fd, buf->content, BUFFER_SIZE);
}

int	find_eol(t_buf *buf)
{
	char	c;

	while (buf->cursor < BUFFER_SIZE)
	{
		c = (buf->content)[buf->cursor];
		if (c == '\n' || c == '\0')
		{
			if (buf->len != BUFFER_SIZE)
				buf->not_empty = 0;
			else
				buf->not_empty = 1;
			return (1);
		}
		buf->cursor++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char			*line;
	static t_buf	buf;

	line = fill_line(buf);
	if (!line)
		return (NULL);
	fill_buffer(&buf, fd);
	if (buf.len <= 0)
		return (free_and_exit(line));
	while (!find_eol(&buf) && buf.len == BUFFER_SIZE)
	{
		line = strcaldupcat(line, buf);
		if (!line)
			return (NULL);
		fill_buffer(&buf, fd);
		if (buf.len < 0)
			return (free_and_exit(line));
	}
	line = strcaldupcat(line, buf);
	if (!line)
		return (NULL);
	return (line);
}
