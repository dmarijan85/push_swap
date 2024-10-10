/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:29:02 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/16 12:08:55 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_nodes(t_node *astack, t_node *bstack)
{
	t_node	*target;
	t_node	*temp_a;
	long	highest;

	while (bstack)
	{
		highest = LONG_MAX;
		temp_a = astack;
		while (temp_a)
		{
			if (temp_a->value > bstack->value && temp_a->value < highest)
			{
				target = temp_a;
				highest = temp_a->value;
			}
			temp_a = temp_a->next;
		}
		if (highest == LONG_MAX)
			bstack->target_node = find_smallest(astack);
		else
			bstack->target_node = target;
		bstack = bstack->next;
	}
}

void	set_position(t_node *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	while (stack)
	{
		stack->current_position = i;
		if (i <= stack_len(stack) / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	set_price(t_node *astack, t_node *bstack)
{
	int	alen;
	int	blen;

	alen = stack_len(astack);
	blen = stack_len(bstack);
	while (bstack)
	{
		bstack->push_price = bstack->current_position;
		if (bstack->above_median == 0)
			bstack->push_price = blen - (bstack->current_position);
		if (bstack->target_node->above_median == 1)
			bstack->push_price += bstack->target_node->current_position;
		else
			bstack->push_price += alen \
							- (bstack->target_node->current_position);
		bstack = bstack->next;
	}
}

void	set_cheapest(t_node *bstack)
{
	long	best_match;
	t_node	*target_node;

	if (!bstack)
		return ;
	best_match = LONG_MAX;
	while (bstack)
	{
		if (bstack->push_price < best_match)
		{
			best_match = bstack->push_price;
			target_node = bstack;
		}
		bstack = bstack->next;
	}
	target_node->cheapest = 1;
}
