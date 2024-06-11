/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:59 by adshafee          #+#    #+#             */
/*   Updated: 2024/03/31 20:40:11 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	**ft_split(char *s)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	split = malloc(sizeof(t_array) * 1024);
	j = 0;
	i = 0;
	while (s[i] < 32)
		i++;
	while (s[i])
	{
		if (s[i] > 32)
		{
			k = 0;
			split[j] = malloc(sizeof(t_array) * 1024);
			while (s[i] > 32)
				split[j][k++] = s[i++];
			split[j++][k] = '\0';
		}
		else
			i++;
	}
	split[j] = 0;
	return (split);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr_str;
	size_t	i;

	ptr_str = (char *)b;
	i = 0;
	while (len > i)
	{
		ptr_str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
