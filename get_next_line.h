/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:41:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 17:50:12 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

typedef struct s_buf {
	char	content[BUFFER_SIZE];
	size_t	cursor;
	ssize_t	len;
	int		not_empty;
}	t_buf;

char	*get_next_line(int fd);
int		find_eol(t_buf *buf);
char	*strcaldupcat(char *line, t_buf buf);
char	*free_and_exit(char *str);
void	fill_buffer(t_buf *buf, int fd);
char	*fill_line(t_buf buf);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
