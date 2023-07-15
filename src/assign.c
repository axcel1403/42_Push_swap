/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:55:55 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:23:59 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = ft_lstsize(tmp_a);
	size_b = ft_lstsize(tmp_b);
	while (tmp_b != NULL)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->tgt_pos;
		if (tmp_b->tgt_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->tgt_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

int	assign_target(t_list **stack_a, int b_index, int tgt_index, int tgt_pos)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if ((tmp->index > b_index) && (tmp->index < tgt_index))
		{
			tgt_index = tmp->index;
			tgt_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (tgt_index != INT_MAX)
		return (tgt_pos);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->index < tgt_index)
		{
			tgt_index = tmp->index;
			tgt_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (tgt_pos);
}

void	assign_positions(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	assign_target_position(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_stack_b;
	int		tgt_pos;

	tmp_stack_b = *stack_b;
	assign_positions(stack_a);
	assign_positions(stack_b);
	tgt_pos = 0;
	while (tmp_stack_b != NULL)
	{
		tgt_pos = assign_target(stack_a, tmp_stack_b->index, INT_MAX, tgt_pos);
		tmp_stack_b->tgt_pos = tgt_pos;
		tmp_stack_b = tmp_stack_b->next;
	}
}
