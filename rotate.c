/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:09:40 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:36:09 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*last_node;
	int		len;

	len = stack_len(*stack);
	if (!stack || !*stack || len == 1)
		return (-1);
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	return (1);
}

void	ra(t_node **astack, int isprint)
{
	int	i;

	i = rotate(astack);
	if (i != -1 && isprint == 1)
		ft_printf("ra\n");
}

void	rb(t_node **bstack, int isprint)
{
	int	i;

	i = rotate(bstack);
	if (i != -1 && isprint == 1)
		ft_printf("rb\n");
}

void	rr(t_node **astack, t_node **bstack, int isprint)
{
	int	i;
	int	j;

	i = rotate(astack);
	j = rotate(bstack);
	if ((i != -1 || j != -1) && isprint == 1)
		ft_printf("rr\n");
}
