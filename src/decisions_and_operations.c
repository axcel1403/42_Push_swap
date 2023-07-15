/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decisions_and_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:53:12 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:32:07 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	high;

	if (is_sorted_lst(stack_a))
		return ;
	high = find_high(stack_a);
	if ((*stack_a)->next->index == high)
		rra(stack_a);
	else if ((*stack_a)->index == high)
		ra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	rotate_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	lowest_pos = lowest_index_position(stack_a);
	stack_size = ft_lstsize(*stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_lstsize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && (pushed < stack_size / 2))
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	main_algo(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		assign_target_position(stack_a, stack_b);
		assign_cost(stack_a, stack_b);
		do_best_move(stack_a, stack_b);
	}
	if (!is_sorted_lst(stack_a))
		rotate_stack(stack_a);
}

void	decisions_operations(t_utils *utils, t_list **stack_a, t_list **stack_b)
{
	if (utils->s_size == 2)
		sa(stack_a);
	else if (utils->s_size == 3)
		sort_3(stack_a);
	else if (utils->s_size > 3)
		main_algo(stack_a, stack_b);
}
