/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 03:15:56 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 03:17:22 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
	else
		ft_putchar_fd('\0', fd);
	return (1);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(ft_strlen((char *)s1) * sizeof(char) + 1);
	if (tmp == NULL)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!buffer)
		return (NULL);
	ft_strlcpy(buffer, s1, len1 + 1);
	ft_strlcat(buffer, s2, len2 + len1 + 1);
	return (buffer);
}
