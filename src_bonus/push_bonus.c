/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:15:51 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 20:10:47 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	}
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	if (stack_a || *stack_a)
	{
		push(stack_a, stack_b);
	}
}
