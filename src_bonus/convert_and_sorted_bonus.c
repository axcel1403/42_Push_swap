/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_sorted_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:55:33 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 19:56:52 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	index_to_list(t_utils *utils, t_list *stack_a)
{
	t_list	*tmp;
	t_list	*test;
	int		i;

	i = 0;
	tmp = stack_a;
	test = stack_a;
	while (i < utils->s_size)
	{
		tmp->index = utils->arr_index[i];
		tmp = tmp->next;
		i++;
	}
}

void	int_to_index(t_utils *utils, int tmp_size)
{
	int		i;
	int		j;
	ssize_t	index;
	ssize_t	high;

	i = 0;
	while (i < utils->s_size)
	{
		j = 0;
		high = LONG_MIN;
		while (j < utils->s_size)
		{
			if (utils->arr_int[j] > high)
			{
				high = utils->arr_int[j];
				index = j;
			}
			j++;
		}
		utils->arr_int[index] = LONG_MIN;
		utils->arr_index[index] = tmp_size;
		tmp_size--;
		i++;
	}
}

t_list	*int_to_list(t_utils *utils)
{
	t_list	*stack_a;
	t_list	*new_elem;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < utils->s_size)
	{
		new_elem = ft_lstnew(utils->arr_int[i]);
		ft_lstadd_back(&stack_a, new_elem);
		i++;
	}
	return (stack_a);
}

int	is_sorted_lst(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	is_sorted_arr(t_utils *utils)
{
	int	i;
	int	j;

	i = 0;
	while (i < utils->s_size)
	{
		j = i + 1;
		while (j < utils->s_size)
		{
			if (utils->arr_int[i] > utils->arr_int[j])
				return ;
			j++;
		}
		i++;
	}
	printf("OK\n");
	exit (EXIT_SUCCESS);
}
