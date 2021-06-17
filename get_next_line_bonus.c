/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:44:04 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/04/22 13:42:17 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*dst;
	size_t			i;
	unsigned char	*ptr;

	dst = malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ptr = (unsigned char *)dst;
	i = 0;
	if ((count * size) <= 0)
		return (dst);
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (dst);
}

int		assignline(char **gnl, int check, char **line)
{
	size_t	i;
	char	*tempo;
	char	*mask;
	size_t	x;

	x = ft_strlen(*gnl);
	i = 0;
	tempo = NULL;
	if (check < 0)
		return (-1);
	mask = ft_strchr(*gnl, '\n');
	if (!mask)
	{
		*line = ft_strdup(*gnl);
		return (0);
	}
	i = x - ft_strlen(mask);
	*line = ft_substr(*gnl, 0, i);
	tempo = ft_substr(*gnl, i + 1, x);
	free(*gnl);
	*gnl = ft_strdup(tempo);
	free(tempo);
	tempo = NULL;
	return (1);
}

char	*mallocstock(int fd, char *stock)
{
	if (!(stock = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (NULL);
	if (read(fd, stock, 0) == -1)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	return (stock);
}

int		findline(int fd, char **gnl)
{
	int			spot;
	char		*tmp;
	char		*stock;

	stock = NULL;
	if (!(stock = mallocstock(fd, stock)))
		return (-1);
	spot = 1;
	while (!(ft_strchr(*gnl, '\n')) && spot)
	{
		spot = read(fd, stock, BUFFER_SIZE);
		if (spot)
		{
			stock[spot] = '\0';
			if (!(tmp = ft_strjoin(*gnl, stock)))
				return (-1);
			free(*gnl);
			*gnl = ft_strdup(tmp);
			free(tmp);
			tmp = NULL;
		}
	}
	free(stock);
	stock = NULL;
	return (spot);
}

int		get_next_line(int fd, char **line)
{
	static char	*gnl;
	int			check;

	check = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (gnl == NULL)
	{
		if (!(gnl = (char *)calloc(0, sizeof(char))))
			return (-1);
	}
	check = findline(fd, &gnl);
	check = assignline(&gnl, check, line);
	if (check == 0)
	{
		free(gnl);
		gnl = NULL;
		return (check);
	}
	return (check);
}
