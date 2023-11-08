/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:55 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_buf	buf;

	line = fill_line(buf);
	if (!line)
		return (NULL);
	fill_buffer(&buf, fd);
	if (buf.len <= 0)
		return (NULL);
	while (!find_eol(buf.content, &(buf.cursor)) && buf.len == BUFFER_SIZE)
	{
		line = strcaldupcat(line, ft_strlen(line), buf);
		if (!line)
			return (free_and_exit(line));
		fill_buffer(&buf, fd);
		if (buf.len < 0)
			return (free_and_exit(line));
	}
	line = strcaldupcat(line, ft_strlen(line), buf);
	if (!line)
		return (free_and_exit(line));
	if (buf.len != buf.cursor)
		buf.not_empty = 1;
	return (line);
}
