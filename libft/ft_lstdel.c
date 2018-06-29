/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 05:16:06 by bsiche            #+#    #+#             */
/*   Updated: 2018/05/21 22:10:36 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *list)
{
	t_list *next;

	list = ft_lstgetfirst(list);
	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
	free(list);
}
