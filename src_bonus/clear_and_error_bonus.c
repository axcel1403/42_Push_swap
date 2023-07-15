/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_and_error_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:55:58 by jmiranda          #+#    #+#             */
/*   Updated: 2023/05/01 20:27:19 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	clear_stack(t_list	*stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_SUCCESS);
}

void	clear_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	clear_and_exit(t_list **stack_a, t_list **stack_b, char *move)
{
	free(move);
	clear_stack(*stack_a);
	clear_stack(*stack_b);
	error();
}
