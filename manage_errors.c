/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:46:27 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 12:36:19 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	current = *stack;
	if (!stack || !*stack)
		return ;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_node **astack)
{
	stack_free(astack);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
