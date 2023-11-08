/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:33 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 15:57:28 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(t_buf buf)
{
	char	*line;
	size_t	i;

	i = -1;
	if (buf.not_empty)
	{
		buf.not_empty = 0;
		line = (char *)malloc((BUFFER_SIZE - buf.cursor + 1) * sizeof(char *));
		if (!line)
			return (NULL);
		while ((++i) + buf.cursor < BUFFER_SIZE)
			line[i] = buf.content[i + buf.cursor];
		line[i + buf.cursor] = '\0';
	}
	else
	{
		line = (char *)malloc(1 * sizeof(char *));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	return (line);
}

void	fill_buffer(t_buf *buf, int fd)
{
	if (buf->len == buf->cursor)
		buf->cursor = 0;
	buf->len = read(fd, buf->content, BUFFER_SIZE);
}

int	find_eol(char *content, size_t *cursor)
{
	while (*cursor < BUFFER_SIZE)
	{
		if (content[*cursor] == '\n' || content[*cursor] == '\0')
			return (1);
		(*cursor)++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*free_and_exit(char *str)
{
	free(str);
	return (NULL);
}

char	*strcaldupcat(char *origin, size_t s_ori, t_buf buf)
{
	char	*new;
	size_t	i;

	new = (char *)malloc((s_ori + buf.cursor + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < s_ori)
		new[i] = origin[i];
	i = -1;
	while (++i < buf.cursor)
		new[s_ori + i] = (buf.content)[i];
	new[s_ori + i] = '\0';
	free(origin);
	return (new);
}
