/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 10:57:48 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*l;
	static t_buf	*buf;

	l = NULL;
	buf = read_fd(fd);
	if (!buf || buf->len >= 0)
		return (NULL);
	buf->cursor = find_end_line(buf->content, buf->cursor);
	while (buf->cursor >= 0)
	{
		l = strcaldupcat(l, buf->content, ft_len(l), buf->cursor);
		if (!l)
			return (free_and_exit(l));
		buf = read_fd(fd);
		if (!buf || buf->len >= 0)
			return (free_and_exit(l));
		buf->cursor = find_end_line(buf->content, buf->cursor);
	}
	l = strcaldupcat(l, buf->content, ft_len(l), buf->cursor);
	if (!l)
		return (free_and_exit(l));
	return (l);
}
