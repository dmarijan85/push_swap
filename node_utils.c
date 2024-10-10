/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:53:22 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:22:04 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_both(t_node **astack, t_node **bstack, t_node *cheapest)
{
	while (*astack != cheapest->target_node && *bstack != cheapest)
		rrr(astack, bstack, 1);
	set_position(*astack);
	set_position(*bstack);
}

void	rotate_both(t_node **astack, t_node **bstack, t_node *cheapest)
{
	while (*astack != cheapest->target_node && *bstack != cheapest)
		rr(astack, bstack, 1);
	set_position(*astack);
	set_position(*bstack);
}

void	update_nodes(t_node *astack, t_node *bstack)
{
	set_position(astack);
	set_position(bstack);
	set_target_nodes(astack, bstack);
	set_price(astack, bstack);
	set_cheapest(bstack);
}

void	move_nodes(t_node **astack, t_node **bstack)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*bstack);
	if (cheapest_node->above_median == 1 && \
			cheapest_node->target_node->above_median == 1)
		rotate_both(astack, bstack, cheapest_node);
	else if (cheapest_node->above_median == 0 && \
			cheapest_node->target_node->above_median == 0)
		reverse_rotate_both(astack, bstack, cheapest_node);
	finish_rotate(bstack, cheapest_node, 'b');
	finish_rotate(astack, cheapest_node->target_node, 'a');
	pa(astack, bstack, 1);
}

void	finish_rotate(t_node **stack, t_node *target_node, char name)
{
	while (*stack != target_node)
	{
		if (name == 'a')
		{
			if (target_node->above_median == 1)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (name == 'b')
		{
			if (target_node->above_median == 1)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
