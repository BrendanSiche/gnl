/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsiche <bsiche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 04:52:49 by bsiche            #+#    #+#             */
/*   Updated: 2018/05/14 18:21:18 by bsiche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list *listelement, t_list *newelement)
{
	newelement->index = (listelement->index + 1);
	newelement->prev = listelement;
	newelement->next = NULL;
	listelement->next = newelement;
}
