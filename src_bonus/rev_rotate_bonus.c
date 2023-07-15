/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:16:34 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 20:10:59 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*b4_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		b4_last = tmp;
		tmp = tmp->next;
	}
	b4_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_list **stack_a)
{
	rev_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
