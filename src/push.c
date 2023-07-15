/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:06:33 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 23:06:53 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*tmp;

	if (*stack_src == NULL)
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	tmp->next = *stack_dst;
	*stack_dst = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	if (stack_b || *stack_b)
	{
		push(stack_b, stack_a);
		printf("pa\n");
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (stack_a || *stack_a)
	{
		push(stack_a, stack_b);
		printf("pb\n");
	}
}
