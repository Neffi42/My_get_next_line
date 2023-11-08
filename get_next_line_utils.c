/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:33 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 18:13:50 by abasdere         ###   ########.fr       */
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
		buf.cursor++;
		line = (char *)calloc((BUFFER_SIZE - buf.cursor + 1), sizeof(char *));
		if (!line)
			return (NULL);
		while ((++i) + buf.cursor < BUFFER_SIZE)
			line[i] = buf.content[i + buf.cursor];
		line[i + buf.cursor] = '\0';
	}
	else
	{
		line = (char *)calloc(1, sizeof(char *));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	return (line);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			mem_size;

	ptr = 0;
	i = 0;
	if (!size)
		return (NULL);
	mem_size = nmemb * size;
	if (mem_size / size != nmemb)
		return (NULL);
	ptr = malloc(mem_size);
	if (!ptr)
		return (NULL);
	while (i < mem_size)
		ptr[i++] = 0;
	return ((void *)ptr);
}

char	*free_and_exit(char *str)
{
	free(str);
	return (NULL);
}

char	*strcaldupcat(char *line, t_buf buf)
{
	char	*new_l;
	size_t	i;
	size_t	s_line;
	size_t	s_cont;

	s_line = 0;
	if (buf.len == BUFFER_SIZE)
		s_cont = buf.cursor;
	else
		s_cont = buf.len;
	while (line[s_line])
		s_line++;
	new_l = (char *)calloc((s_line + s_cont + 1), sizeof(char *));
	if (!new_l)
		return (free_and_exit(line));
	i = -1;
	while (++i < s_line)
		new_l[i] = line[i];
	i = -1;
	free(line);
	while (++i < s_cont + 1)
		new_l[s_line + i] = (buf.content)[i];
	new_l[s_line + i] = '\0';
	return (new_l);
}
