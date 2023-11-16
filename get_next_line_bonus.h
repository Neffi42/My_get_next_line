/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasdere <abasdere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:29:36 by abasdere          #+#    #+#             */
/*   Updated: 2023/11/16 15:32:58 by abasdere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
int		is_new_line(char *result);
ssize_t	read_buffer(char **buf, int fd);
char	*process_buffer(char *buf, char *process);
size_t	find_new_line(char *buf);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
