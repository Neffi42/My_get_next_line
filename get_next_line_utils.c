/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:33 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 11:00:16 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buf	*read_fd(int fd)
{
	t_buf	*buf;

	buf = (t_buf *)malloc(1 * sizeof(t_buf *));
	if (!buf)
		return (NULL);
	buf->len = read(fd, buf->content, BUFFER_SIZE);
	return (buf);
}

size_t	find_end_line(char *content, size_t cursor)
{
	while (cursor < BUFFER_SIZE)
	{
		if (content[cursor] == '\n' || content[cursor] == '\0')
			return (cursor);
		cursor++;
	}
	return (-1);
}

size_t	ft_len(char *str)
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

char	*strcaldupcat(char *origin, char *content, size_t s_ori, size_t cursor)
{
	char	*new;
	size_t	i;

	new = (char *)malloc((s_ori + cursor + 1) * sizeof(char *));
	if (!new)
		return	(NULL);
	i = -1;
	while (++i < s_ori)
		new[i] = origin[i];
	i = -1;
	while (++i < cursor)
		new[s_ori + i] = content[i];
	new[s_ori + i] = '\0';
	return (new);
}
