/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_and_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:00:40 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:23:57 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_index_position(t_list **stack_a)
{
	t_list	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack_a;
	lowest_index = INT_MAX;
	assign_positions(stack_a);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	find_high(t_list **stack_a)
{
	int		index;
	t_list	*tmp;

	tmp = *stack_a;
	index = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

int	absolute(int number)
{
	int	convert;

	convert = -1;
	if (number < 0)
		return (number * convert);
	return (number);
}

void	rotate_decision_b(t_list **stack_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rb(stack_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			rrb(stack_b);
			(*cost_b)++;
		}
	}
}
