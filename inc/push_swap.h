/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:53:31 by jmiranda          #+#    #+#             */
/*   Updated: 2023/04/15 22:45:00 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_utils
{
	ssize_t	arr_int[500];
	ssize_t	arr_index[500];
	int		s_size;
}	t_utils;

int		valid_args(int argc, char **argv, t_utils *utils);
int		is_number(char **argv);
void	argv_to_int(char **numbers, t_utils *utils);
void	is_duplicate(t_utils *utils);
void	is_sorted_arr(t_utils *utils);
t_list	*int_to_list(t_utils *utils);
void	int_to_index(t_utils *utils, int tmp_size);
void	index_to_list(t_utils *utils, t_list *stack_a);
void	decisions_operations(t_utils *utils, t_list **stack_a,
			t_list **stack_b);
void	main_algo(t_list **stack_a, t_list **stack_b);
void	push_all_save_three(t_list **stack_a, t_list **stack_b);
void	rotate_stack(t_list **stack_a);
int		lowest_index_position(t_list **stack_a);
void	assign_target_position(t_list **stack_a, t_list **stack_b);
void	assign_positions(t_list **stack);
int		assign_target(t_list **stack_a, int b_index,
			int tgt_index, int tgt_pos);
void	assign_cost(t_list **stack_a, t_list **stack_b);
void	do_best_move(t_list **stack_a, t_list **stack_b);
int		absolute(int number);
void	move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b);
void	rev_rotate_both(t_list **stack_a, t_list **stack_b,
			int *cost_a, int *cost_b);
void	rotate_both(t_list **stack_a, t_list **stack_b,
			int *cost_a, int *cost_b);
void	rotate_decision_a(t_list **stack_a, int *cost_a);
void	rotate_decision_b(t_list **stack_b, int *cost_b);
void	sort_3(t_list **stack_a);
int		is_sorted_lst(t_list **stack_a);
int		find_high(t_list **stack_a);
void	ss(t_list **stack_a, t_list **stack_b);
void	sb(t_list **stack_b);
void	sa(t_list **stack_a);
void	swap(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rotate(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rev_rotate(t_list **stack);
void	pb(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_src, t_list **stack_dst);
void	clear_tab(char **tab);
void	error(void);
void	clear_stack(t_list	*stack);

#endif 
