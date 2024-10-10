/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:54:22 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:36:19 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverserotate(t_node **stack)
{
	t_node	*last;
	int		len;

	len = stack_len(*stack);
	if (!*stack || !stack || len == 1)
		return (-1);
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	return (1);
}

void	rra(t_node **astack, int isprint)
{
	int	i;

	i = reverserotate(astack);
	if (i != -1 && isprint == 1)
		ft_printf("rra\n");
}

void	rrb(t_node **bstack, int isprint)
{
	int	i;

	i = reverserotate(bstack);
	if (i != -1 && isprint == 1)
		ft_printf("rrb\n");
}

void	rrr(t_node **astack, t_node **bstack, int isprint)
{
	int	i;
	int	j;

	i = reverserotate(astack);
	j = reverserotate(bstack);
	if ((i != -1 || j != -1) && isprint == 1)
		ft_printf("rrr\n");
}
