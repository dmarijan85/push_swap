/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:20:35 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:38:24 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!*src)
		return (-1);
	temp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dest)
	{
		*dest = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dest;
		temp->next->prev = temp;
		*dest = temp;
	}
	return (1);
}

void	pa(t_node **astack, t_node **bstack, int isprint)
{
	int	i;

	i = push(astack, bstack);
	if (i != -1 && isprint == 1)
		ft_printf("pa\n");
}

void	pb(t_node **astack, t_node **bstack, int isprint)
{
	int	i;

	i = push(bstack, astack);
	if (i != -1 && isprint == 1)
		ft_printf("pb\n");
}
