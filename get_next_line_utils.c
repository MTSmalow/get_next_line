/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmedeir <edmedeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:29:45 by edmedeir          #+#    #+#             */
/*   Updated: 2026/06/07 10:57:21 by edmedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	cont;

	cont = 0;
	while (s[cont])
		cont++;
	return (cont);
}

int	search_nline(char *ptr)
{
	int	cont;

	cont = 0;
	if (!ptr)
		return (0);
	while (ptr[cont])
	{
		if (ptr[cont] == '\n')
			return (1);
		cont++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	joined = (char *)malloc(sizeof (char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (free(s1), NULL);
	while (s1[++i])
		joined[i] = s1[i];
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	return (free(s1), joined);
}
