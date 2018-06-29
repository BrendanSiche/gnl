/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 00:49:03 by bsiche            #+#    #+#             */
/*   Updated: 2018/06/17 03:06:12 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readline(t_fd *fd)
{
	char	tmp[BUFF_SIZE + 1];
	int		loop;

	loop = read(fd->number, tmp, BUFF_SIZE);
	tmp[loop] = '\0';
	if ((fd->buff = ft_strjoin(fd->buff, tmp, 1)) == NULL)
		return (-1);
	else
		return (loop);
}

t_list	*get_by_fd(t_lstcontainer *liste, int fd)
{
	t_list	*tmp;
	t_fd	*file;

	tmp = liste->firstelement;
	while (tmp)
	{
		file = (t_fd *)tmp->content;
		if (file->number == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((file = malloc(sizeof(t_fd *))) == NULL)
		return (NULL);
	file->buff = ft_strnew(0);
	file->number = fd;
	liste->add(liste, file, sizeof(file));
	return (ft_lstgetlast(liste->firstelement));
}

int		gnl(char **line, t_fd *fd)
{
	int		i;
	int		loop;

	i = 0;
	loop = 1;
	while (loop > 0)
	{
		if (ft_strchr(fd->buff, '\n') != NULL)
		{
			while ((fd->buff)[i] != '\n')
				i++;
			if ((*line = ft_strsub(fd->buff, 0, i, 0)) == NULL)
				return (-1);
			fd->buff = ft_strsub(fd->buff, i + 1, ft_strlen(fd->buff), 1);
			return (1);
		}
		loop = readline(fd);
	}
	if (loop == 0 && ft_strlen(fd->buff) != 0)
	{
		*line = ft_strdup(fd->buff);
		fd->buff = ft_strnew(0);
		return (1);
	}
	return (loop);
}

int		get_next_line(int const fd, char **line)
{
	static t_lstcontainer	*liste;
	t_list					*cur_fd;
	t_fd					*tmp;
	int						a;

	if (!line || fd < 0)
		return (-1);
	if (liste == NULL)
		liste = lstcontainer_new();
	if ((cur_fd = get_by_fd(liste, fd)) == NULL)
		return (-1);
	tmp = cur_fd->content;
	a = gnl(line, tmp);
	if (a == 0 || a == -1)
		liste->remove(cur_fd);
	return (a);
}
