/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:33 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 11:55:49 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	find_end_line(char *content, ssize_t cursor)
{
	while (cursor < BUFFER_SIZE)
	{
		if (content[cursor] == '\n' || content[cursor] == '\0')
			return (cursor);
		cursor++;
	}
	return (-1);
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

char	*strcaldupcat(char *origin, char *content, size_t s_ori, size_t cursor)
{
	char	*new;
	size_t	i;

	new = (char *)malloc((s_ori + cursor + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < s_ori)
		new[i] = origin[i];
	i = -1;
	while (++i < cursor)
		new[s_ori + i] = content[i];
	new[s_ori + i] = '\0';
	return (new);
}
