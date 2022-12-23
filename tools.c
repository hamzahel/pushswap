/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:04:19 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/14 19:25:14 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	if (size < i)
		i = size;
	j = 0;
	while ((int)(j) < (int)(size - i - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < size)
		dst[i + j] = 0;
	return (i + ft_strlen((char *)src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (lensrc);
	while (size - 1 > i && lensrc > 0)
	{
		dst[i] = src[i];
		i++;
		lensrc--;
	}
	dst[i] = '\0';
	return (lensrc + i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static int	lonmax(char *str, int si)
{
	if (ft_strncmp(str, "9223372036854775807", 19) > 0 && si)
		return (-1);
	else if (ft_strncmp(str, "9223372036854775808", 19) > 0 && !(si))
		return (0);
	else
		return (1);
}

long	ft_atoi(const char *str)
{
	long	result;
	int		i;
	int		si;
	int		counter;
	int		bg;

	result = 0;
	counter = 0;
	i = 0;
	si = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		si = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	bg = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if ((counter++) >= 19 && lonmax((char *)&str[bg], si) != 1)
			return (0);
	}
	return (result * si);
}
