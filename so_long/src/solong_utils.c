/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:49:12 by lchapard          #+#    #+#             */
/*   Updated: 2024/01/08 15:49:17 by lchapard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/map.h"

size_t	ft_strlenmap(const char *s)
{
	size_t	i;
	size_t	cpt;

	i = 0;
	cpt = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		cpt++;
		i++;
	}
	return (cpt);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while ((s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i])
		return (-1);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*sr;

	sr = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			sr = s;
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return ((char *)sr);
}

void	name_is_valid(char *str)
{
	str = ft_strrchr(str, 46);
	if (str == NULL)
	{
		ft_printf("Error !\n No file type was found!\n");
		exit(0);
	}
	if (ft_strcmp(str, ".ber") != 0)
	{
		ft_printf("Error !\nMap name must be of .ber type!\n");
		exit(0);
	}
}
