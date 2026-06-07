/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:59:28 by edmedeir          #+#    #+#             */
/*   Updated: 2026/06/07 09:41:04 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*cln_r(char *ptr);
char	*ext_l(char *ptr);
char	*read_fd(int fd, char *reds);

int		search_nline(char *ptr);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
