/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_validity_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:20:37 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:20:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check if args are numbers only, within the int range,
without duplicates, and non sorted yet. 
also return an arr of int with the nums to sort */

static void	check_if_data_is_int(char **input, t_data *data)
{
	int		errors;

	data->i = 0;
	errors = 0;
	while (data->i < data->stack_size)
		errors += is_int_compatible(input[data->i++]);
	if (errors > 0)
	{
		free_split(input);
		error_and_exit(data);
	}
}

static void	check_dup_and_sorted_arr(t_data *data, int *nums)
{
	if (check_if_duplicates(nums, data->stack_size) != 0)
	{
		free(nums);
		error_and_exit(data);
	}
	data->is_sorted = check_if_already_sorted(nums, data->stack_size);
	if (data->is_sorted == -1)
	{
		free(nums);
		error_and_exit(data);
	}
}

int	*check_args_are_valid(char **input, t_data *data)
{
	int		*nums;

	check_if_data_is_int(input, data);
	nums = (int *)malloc(sizeof(int) * (data->stack_size));
	if (!nums)
	{
		free_split(input);
		error_and_exit(data);
	}
	data->i = 0;
	while (data->i < data->stack_size)
	{
		nums[data->i] = ft_atoi(input[data->i]);
		data->i++;
	}
	free_split(input);
	check_dup_and_sorted_arr(data, nums);
	return (nums);
}
