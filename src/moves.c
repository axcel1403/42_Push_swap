/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:58:50 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:00:17 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_decision_a(t_list **stack_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ra(stack_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			rra(stack_a);
			(*cost_a)++;
		}
	}
}

void	rotate_both(t_list **stack_a, t_list **stack_b,
													int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b,
													int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_decision_a(stack_a, &cost_a);
	rotate_decision_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}

void	do_best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		best;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	best = INT_MAX;
	while (tmp != NULL)
	{
		if (absolute(tmp->cost_a) + absolute(tmp->cost_b) < absolute(best))
		{
			best = absolute(tmp->cost_b) + absolute(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move(stack_a, stack_b, cost_a, cost_b);
}
