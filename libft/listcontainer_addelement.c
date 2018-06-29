/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcontainer_addelement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 02:45:15 by bsiche            #+#    #+#             */
/*   Updated: 2018/02/27 02:45:19 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lstcontainer_add(t_lstcontainer *container, void *content, size_t size)
{
	if (container->firstelement == NULL)
		container->firstelement = ft_lstnew(content, size);
	else
		ft_lstadd(ft_lstgetlast(container->firstelement),
				ft_lstnew(content, size));
	return (ft_lstgetlast(container->firstelement));
}
