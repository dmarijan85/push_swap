/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:46:00 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/16 12:13:48 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkinstruction(char *instruction, t_node **astack, t_node **bstack)
{
	if (ft_strnstr(instruction, "sa", 2))
		sa(astack, 0);
	else if (ft_strnstr(instruction, "sb", 2))
		sb(bstack, 0);
	else if (ft_strnstr(instruction, "ss", 2))
		ss(astack, bstack, 0);
	else if (ft_strnstr(instruction, "pa", 2))
		pa(astack, bstack, 0);
	else if (ft_strnstr(instruction, "pb", 2))
		pb(astack, bstack, 0);
	else if (ft_strnstr(instruction, "rra", 3))
		rra(astack, 0);
	else if (ft_strnstr(instruction, "rrb", 3))
		rrb(bstack, 0);
	else if (ft_strnstr(instruction, "rrr", 3))
		rrr(astack, bstack, 0);
	else if (ft_strnstr(instruction, "ra", 2))
		ra(astack, 0);
	else if (ft_strnstr(instruction, "rb", 2))
		rb(bstack, 0);
	else if (ft_strnstr(instruction, "rr", 2))
		rr(astack, bstack, 0);
	else
		return (-2);
	return (1);
}

int	checkinstructionerror(char *instruction, t_node **astack, t_node **bstack)
{
	if (!instruction || !*instruction)
		return (-1);
	return (checkinstruction(instruction, astack, bstack));
}

void	stack_init(t_node **stack, char **argv)
{
	int		i;
	long	coconut;

	i = 0;
	if (!argv)
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

void	mainhelper(t_node **astack, t_node **bstack)
/* running out of space MAN */
{
	int		flag;
	char	*instruction;

	flag = 0;
	while (flag >= 0)
	{
		instruction = get_next_line(0);
		flag = checkinstructionerror(instruction, astack, bstack);
	}
	if (flag == -2)
		ft_printstderr("Error\n");
	else if (is_sorted(*astack) && !*bstack)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(instruction);
}

int	main(int argc, char **argv)
{
	t_node	*astack;
	t_node	*bstack;

	argc = 0;
	stack_init(&astack, argv + 1);
	mainhelper(&astack, &bstack);
	stack_free(&astack);
	stack_free(&bstack);
	return (0);
}
