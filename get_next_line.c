/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:58:38 by edmedeir          #+#    #+#             */
/*   Updated: 2026/06/07 09:53:31 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *reds)
{
	char		*buffer;
	ssize_t		byt_red;

	if (!(fd >= 0))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byt_red = 1;
	while (byt_red > 0 && !search_nline(reds))
	{
		byt_red = read(fd, buffer, BUFFER_SIZE);
		if (byt_red == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byt_red] = '\0';
		reds = ft_strjoin_gnl(reds, buffer);
	}
	free(buffer);
	return (reds);
}

char	*ext_l(char *ptr)
{
	char	*l;
	int		cont;
	int		i;

	if (!ptr || !ptr[0])
		return (NULL);
	cont = 0;
	while (ptr[cont] && ptr[cont] != '\n')
		cont++;
	if (ptr[cont] == '\n')
		cont++;
	l = malloc(sizeof(char) * (cont + 1));
	if (!l)
		return (NULL);
	i = 0;
	while (i < cont)
	{
		l[i] = ptr[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*cln_r(char *ptr)
{
	int		cont;
	int		cont2;
	char	*rest;

	cont = 0;
	cont2 = 0;
	while (ptr[cont] && ptr[cont] != '\n')
		cont++;
	if (!ptr[cont])
		return (free(ptr), NULL);
	rest = malloc(sizeof(char) * (ft_strlen(ptr) - cont));
	if (!rest)
		return (free(ptr), NULL);
	while (ptr[++cont])
	{
		rest[cont2] = ptr[cont];
		cont2++;
	}
	rest[cont2] = '\0';
	return (free(ptr), rest);
}

char	*get_next_line(int fd)
{
	static char	*reds;
	char		*l;

	reds = read_fd(fd, reds);
	if (!reds)
		return (NULL);
	if (reds[0] == '\0')
	{
		free(reds);
		reds = NULL;
		return (NULL);
	}
	l = ext_l(reds);
	reds = cln_r(reds);
	return (l);
}
