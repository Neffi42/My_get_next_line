/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:29:40 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/16 15:33:14 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *result, char *process)
{
	size_t	i;
	size_t	size_r;
	size_t	size_b;
	char	*join;

	size_r = 0;
	if (result)
		size_r = ft_strlen(result);
	size_b = ft_strlen(process);
	join = malloc((size_r + size_b + 1) * sizeof(char));
	if (!join)
		return (free(result), free(process), NULL);
	i = -1;
	while (++i < size_r)
		join[i] = result[i];
	i = -1;
	while (++i < size_b)
		join[i + size_r] = process[i];
	join[i + size_r] = '\0';
	return (free(result), free(process), join);
}
