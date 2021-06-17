/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlebouvi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:48:21 by tlebouvi          #+#    #+#             */
/*   Updated: 2021/04/22 13:52:41 by tlebouvi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

void			*ft_calloc(size_t count, size_t size);
int				assignline(char **gnl, int check, char **line);
char			*mallocstock(int fd, char *stock);
int				findline(int fd, char **gnl);
char			*ft_strchr(const char *str, int searched);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const*s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);
char			*ft_strdup(const char *str);

#endif
