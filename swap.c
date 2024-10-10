/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:49:02 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:37:41 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **head)
{
	int	len;

	len = stack_len(*head);
	if (!*head || !head || len == 1)
		return (-1);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (1);
}

void	sa(t_node **astack, int isprint)
{
	int	i;

	i = swap(astack);
	if (i != -1 && isprint == 1)
		ft_printf("sa\n");
}

void	sb(t_node **bstack, int isprint)
{
	int	i;

	i = swap(bstack);
	if (i != -1 && isprint == 1)
		ft_printf("sb\n");
}

void	ss(t_node **astack, t_node **bstack, int isprint)
{
	int	i;
	int	j;

	i = swap(astack);
	j = swap(bstack);
	if ((i != -1 || j != -1) && isprint == 1)
		ft_printf("ss\n");
}
