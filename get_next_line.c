/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:31 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/10 11:43:31 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_buf	buf;


	line = fill_line(&buf);
	if (!line)
		return (NULL);
	fill_buffer(&buf, fd);
	if (buf.len < 0)
		return (free_and_exit(line));
	while (!find_end_of_line(&buf) && buf.len)
	{
		line = ft_strdupcat(line, buf);
		if (!line)
			return (NULL);
		fill_buffer(&buf, fd);
		if (buf.len < 0)
			return (free_and_exit(line));
	}
	line = ft_strdupcat(line, buf);
	if (!line)
		return (NULL);
	return (line);
}

int	find_end_of_line(t_buf *buf)
{
	char	c;

	c = (buf->content)[(buf->cursor)];
	buf->not_empty = 0;
	while (c != '\n' && c != '\0' && (buf->cursor) < BUFFER_SIZE)
		c = (buf->content)[++(buf->cursor)];
	if (buf->cursor == BUFFER_SIZE)
		return (0);
	buf->not_empty = 1;
	return (1);
}

void	fill_buffer(t_buf *buf, int fd)
{
	if (!buf->not_empty)
		buf->cursor = 0;
	buf->len = read(fd, buf->content, BUFFER_SIZE);
}

char	*fill_line(t_buf *buf)
{
	char	*line;
	size_t	i;

	if (buf->not_empty)
	{
		buf->not_empty = 0;
		buf->cursor++;
		line = (char *)ft_calloc((BUFFER_SIZE + 1 - buf->cursor), sizeof(char));
		if (!line)
			return (NULL);
		i = -1;
		while ((++i) < BUFFER_SIZE - buf->cursor)
			line[i] = buf->content[i + buf->cursor];
		line[i] = '\0';
	}
	else
	{
		line = (char *)ft_calloc(1, sizeof(char));
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*ft_strdupcat(char *line, t_buf buf)
{
	char	*new_l;
	size_t	i;
	size_t	s_line;
	size_t	s_cont;

	s_line = 0;
	if (buf.len == BUFFER_SIZE)
		s_cont = buf.cursor + 1;
	else
		s_cont = buf.len;
	while (line[s_line])
		s_line++;
	new_l = (char *)ft_calloc((s_line + s_cont + 1), sizeof(char));
	if (!new_l)
		return (free_and_exit(line));
	i = -1;
	while (++i < s_line)
		new_l[i] = line[i];
	free(line);
	i = -1;
	while (++i < s_cont)
		new_l[s_line + i] = (buf.content)[i];
	new_l[s_line + i] = '\0';
	return (new_l);
}
