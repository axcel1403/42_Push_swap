/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmiranda <jmiranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:57:41 by jmiranda          #+#    #+#             */
/*   Updated: 2023/07/18 12:12:56 by jmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	is_duplicate(t_utils *utils)
{
	int	i;
	int	j;

	i = 0;
	while (i < utils->s_size)
	{
		j = i + 1;
		while (j < utils->s_size)
		{
			if (utils->arr_int[i] == utils->arr_int[j])
				error();
			j++;
		}
		i++;
	}
}

void	argv_to_int(char **numbers, t_utils *utils)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{
		utils->arr_int[utils->s_size] = ft_atoss(numbers[i]);
		(utils->s_size)++;
		if (utils->s_size == 500)
			break ;
		i++;
	}
	i = 0;
	while (i < utils->s_size)
	{
		if (utils->arr_int[i] > INT_MAX || utils->arr_int[i] < INT_MIN)
		{
			clear_tab(numbers);
			error();
		}
		i++;
	}
}

int	is_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && (j == 0 || argv[i][j - 1] == ' '))
			{
				j++;
				if (ft_isdigit(argv[i][j]))
					j++;
				else
					return (0);
			}
			else if (ft_isdigit(argv[i][j]) || (argv[i][j] == ' '))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	valid_args(int argc, char **argv, t_utils *utils)
{
	int		i;
	char	**split_argv;

	if (argc < 2)
		exit (EXIT_SUCCESS);
	else if (argc >= 2 && is_number(argv))
	{
		i = 1;
		utils->s_size = 0;
		while (argv[i] != NULL)
		{
			split_argv = ft_split(argv[i], ' ');
			argv_to_int(split_argv, utils);
			clear_tab(split_argv);
			if (utils->s_size == 500)
				break ;
			i++;
		}
		is_duplicate(utils);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_utils	utils;
	t_list	*stack_a;
	t_list	*stack_b;

	if (valid_args(argc, argv, &utils))
	{
		is_sorted_arr(&utils);
		stack_a = int_to_list(&utils);
		stack_b = NULL;
		int_to_index(&utils, utils.s_size);
		index_to_list(&utils, stack_a);
		checker(&stack_a, &stack_b);
		clear_stack(stack_a);
		clear_stack(stack_b);
	}
	else
		error();
	return (0);
}
