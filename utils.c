/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:44:59 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:18:20 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeat(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	printshit(t_node *astack, t_node *bstack)
{
	t_node	*temp;

	temp = astack;
	if (temp)
	{
		while (temp->next)
		{
			ft_printf("> Stack A:%d\n", temp->value);
			temp = temp->next;
		}
		ft_printf("> Stack A:%d\n", temp->value);
	}
	temp = bstack;
	if (temp)
	{
		while (temp->next)
		{
			ft_printf("> Stack B:%d\n", temp->value);
			temp = temp->next;
		}
		ft_printf("> Stack B:%d\n", temp->value);
	}
}

int	stack_len(t_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

void	append_node(t_node **stack, long nbr)
{
	t_node	*node;
	t_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
