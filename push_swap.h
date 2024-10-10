/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarijan <dmarijan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:40:57 by dmarijan          #+#    #+#             */
/*   Updated: 2024/04/15 15:39:35 by dmarijan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/libft/get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				current_position;
	int				push_price;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_node;

void	array_free(char **buf);
void	stack_free(t_node **stack);
void	error_free(t_node **astack);
void	stack_init(t_node **stack, char **argv);
t_node	*find_last_node(t_node *current);
void	append_node(t_node **stack, long nbr);
t_node	*find_smallest(t_node *stack);
t_node	*find_cheapest(t_node *stack);
int		stack_len(t_node *stack);
void	sa(t_node **stack, int isprint);
void	sb(t_node **bstack, int isprint);
void	ss(t_node **astack, t_node **bstack, int isprint);
void	pa(t_node **astack, t_node **bstack, int isprint);
void	pb(t_node **astack, t_node **bstack, int isprint);
void	ra(t_node **astack, int isprint);
void	rb(t_node **bstack, int isprint);
void	rr(t_node **astack, t_node **bstack, int isprint);
void	rra(t_node **astack, int isprint);
void	rrb(t_node **bstack, int isprint);
void	rrr(t_node **astack, t_node **bstack, int isprint);
t_node	*find_highest(t_node *stack);
t_node	*find_lowest(t_node *stack);
void	tiny_sort(t_node **stack);
void	set_position(t_node *stack);
void	set_target_nodes(t_node *astack, t_node *bstack);
void	set_price(t_node *astack, t_node *bstack);
int		is_sorted(t_node *stack);
void	push_swap(t_node **astack, t_node **bstack);
void	set_cheapest(t_node *bstack);
void	finish_rotate(t_node **stack, t_node *target_node, char name);
void	printshit(t_node *astack, t_node *bstack);
void	update_nodes(t_node *astack, t_node *bstack);
int		is_repeat(char **argv);
void	move_nodes(t_node **astack, t_node **bstack);

#endif
