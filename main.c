/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:32:04 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/16 12:13:31 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_node **stack, char **argv)
{
	int		i;
	long	coconut;

	i = 0;
	if (!argv || !*argv)
		error_free(stack);
	if (is_repeat(argv) != 1)
		return (error_free(stack));
	while (argv[i])
	{
		coconut = ft_atol(argv[i]);
		if (coconut > INT_MAX || coconut < INT_MIN)
			error_free(stack);
		append_node(stack, coconut);
		i++;
	}
}

void	tiny_sort(t_node **stack)
{
	t_node	*highest;

	if (is_sorted(*stack) != 1)
	{
		highest = find_highest(*stack);
		if (*stack == highest)
			ra(stack, 1);
		else if ((*stack)->next == highest)
			rra(stack, 1);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack, 1);
	}
}

void	push_swap(t_node **astack, t_node **bstack)
{
	t_node	*smallest;
	int		alen;

	alen = stack_len(*astack);
	while (alen-- > 3)
		pb(astack, bstack, 1);
	tiny_sort(astack);
	while (*bstack)
	{
		update_nodes(*astack, *bstack);
		move_nodes(astack, bstack);
	}
	set_position(*astack);
	smallest = find_smallest(*astack);
	if (smallest->above_median == 1)
		while (*astack != smallest)
			ra(astack, 1);
	else
		while (*astack != smallest)
			rra(astack, 1);
}

int	main(int argc, char **argv)
{
	t_node	*astack;
	t_node	*bstack;

	if (argc == 1)
		return (-1);
	if (!argv[1][0])
		return (-1);
	stack_init(&astack, argv + 1);
	if (is_sorted(astack) == 0)
	{
		if (stack_len(astack) == 2)
			sa(&astack, 1);
		else
			push_swap(&astack, &bstack);
	}
	stack_free(&astack);
	return (0);
}
