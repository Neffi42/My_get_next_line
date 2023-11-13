/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:46:33 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/13 16:01:39 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	int				mem_size;
	int				i;

	ptr = 0;
	i = 0;
	mem_size = nmemb * size;
	if (size && mem_size / size != nmemb)
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
