/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 09:46:37 by lchapard          #+#    #+#             */
/*   Updated: 2023/12/18 16:02:58 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*ft_grab_line(char *s, size_t n);
size_t	get_bn(char *buf);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_clean_buffer(char *buf);
char	*ft_strdup(const char *s);
char	*read_rest(int fd, char buffer[BUFFER_SIZE + 1], char *ret, int *end);

#endif
