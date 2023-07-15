/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:05:55 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:06:16 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	rev_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	printf("rrr\n");
}
