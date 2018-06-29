/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcontainer_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:15:58 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/25 18:16:00 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		lstcontainer_size(t_lstcontainer *list_container)
{
	t_list	*lst;
	int		size;

	size = 0;
	lst = list_container->firstelement;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
