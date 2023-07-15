/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:46:48 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 20:26:43 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int		is_sorted_lst(t_list **stack_a);
t_list	*int_to_list(t_utils *utils);
void	int_to_index(t_utils *utils, int tmp_size);
void	index_to_list(t_utils *utils, t_list *stack_a);
void	checker(t_list **stack_a, t_list **stack_b);
void	check_and_move(t_list **stack_a, t_list **stack_b, char *move);
void	push(t_list **stack_src, t_list **stack_dst);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rev_rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	clear_stack(t_list	*stack);
void	error(void);
void	clear_tab(char **tab);
void	clear_and_exit(t_list **stack_a, t_list **stack_b, char *move);

#endif
