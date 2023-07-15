/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:13:18 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 22:09:12 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_and_move(t_list **stack_a, t_list **stack_b, char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else
		clear_and_exit(stack_a, stack_b, move);
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move != NULL)
	{
		if (ft_strncmp(move, "\0", 1) == 0 || ft_strncmp(move, "\n", 1) == 0)
		{
			free(move);
			break ;
		}
		check_and_move(stack_a, stack_b, move);
		free(move);
		move = get_next_line(0);
	}
	if ((ft_lstsize(*stack_b) == 0) && is_sorted_lst(stack_a))
		printf("OK\n");
	else
		printf("KO\n");
}
