/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:29:44 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/16 15:45:31 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FD_MAX][BUFFER_SIZE];
	char		*process;
	char		*result;

	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	process = NULL;
	result = NULL;
	while (!is_new_line(result) && read_buffer((char **) &buf[fd], fd) > 0)
	{
		process = process_buffer(buf[fd], process);
		if (!process)
			return (free(result), NULL);
		result = ft_strjoin(result, process);
		if (!result)
			return (NULL);
	}
	return (result);
}

int	is_new_line(char *result)
{
	if (!result)
		return (0);
	if (result[ft_strlen(result) - 1] == '\n')
		return (1);
	return (0);
}

ssize_t	read_buffer(char **buf, int fd)
{
	if (*buf)
		return (1);
	if (read(fd, buf, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

char	*process_buffer(char *buf, char *process)
{
	size_t	i;
	size_t	len;

	len = find_new_line(buf);
	process = malloc(len + 1 * sizeof(char));
	if (!process)
		return (NULL);
	i = -1;
	while (++i < len)
		process[i] = buf[i];
	process[i] = '\0';
	i = -1;
	while (++i < BUFFER_SIZE)
	{
		if (len + i < BUFFER_SIZE)
			buf[i] = buf[len + i];
		else
			buf[i] = '\0';
	}
	return (process);
}

size_t	find_new_line(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i + 1);
	return (i);
}
