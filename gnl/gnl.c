/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 10:51:50 by pcorbeau          #+#    #+#             */
/*   Updated: 2016/03/23 17:13:28 by pcorbeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_remalloc(char *save)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(save))))
		return (0);
	ft_strcpy(tmp, save);
	save = NULL;
	if (!(save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	ft_strcpy(save, tmp);
	free(tmp);
	return (1);
}

int		filler(int i, int y, char *save)
{
	while ((save)[i])
		save[y++] = save[i++];
	save[y] = '\0';
	return (2);
}

int		line_filler(int j, char *save, char **line)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (j != 0 || ft_strlen(save) != 0)
	{
		if (!(*line = ft_strnew(ft_strlen(save + 1))))
			return (0);
		while (ft_isprint(save[i]) == 1 || save[i])
		{
			(*line)[i] = save[i];
			i++;
			if (save[i] == '\n' || save[i] == '\0')
				break ;
		}
		(*line)[i++] = '\0';
		if (save[0] == '\n')
			return (filler(i, y, save));
		while (save[i])
			save[y++] = (save)[i++];
		save[y++] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			j;
	static char	*save[MAX_FD];

	if (fd < 0 || (!save[fd] && !(save[fd] = ft_strnew(BUFF_SIZE + 1))) ||
				(!(*line = ft_strnew(BUFF_SIZE + 1))))
		return (-1);
	while ((j = read(fd, *line, BUFF_SIZE)) > 0)
	{
		if (!(ft_remalloc(save[fd])))
			return (-1);
		ft_strncat(save[fd], *line, BUFF_SIZE);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	if (j == -1)
		return (-1);
	if ((line_filler(j, save[fd], &(*line))) == 2)
		return (1);
	if (ft_strcmp((*line), save[fd]) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (1);
}
