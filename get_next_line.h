/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:41:54 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/08 10:57:02 by abasdere         ###   ########.fr       */
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
}	t_buf;

char	*get_next_line(int fd);
t_buf	*read_fd(int fd);
size_t	find_end_line(char *content, size_t cursor);
char	*strcaldupcat(char *origin, char *content, size_t s_ori, size_t s_cont);
size_t	ft_len(char *str);
char	*free_and_exit(char *str);

#endif
