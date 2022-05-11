/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:30:42 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 20:24:29 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* while pile A is sorted, push fourth number to top of pile A,
then until not sorted, rotate until sorted. Use an algo
to check what direction use the less moves */

void	sort_param_top_b(t_data *data, int *pile_a)
{
	while (42)
	{
		if (check_if_already_sorted(pile_a, data->size_a) == 0)
		{
			if (distance_from_sorted_pos(data->pile_a[0], data,
					data->pile_a, ALPHA) == CLOCK)
				rab(data, data->pile_a, ALPHA);
			else
				rrab(data, data->pile_a, ALPHA);
		}
		else
			break ;
	}
}

/* This algo push the top number into pile B,
then apply the 3 num algo on pile A,
and finally use sort_last_param */

void	algo_case_four_nums(t_data *data)
{
	int			*interval;

	pb(data, data->pile_a, data->pile_b);
	algo_case_three_nums(data, data->pile_a);
	interval = find_interval(data, ALPHA);
	if (!interval)
		free_stacks_and_exit(data);
	if (data->pile_b[0] < interval[0] || data->pile_b[0] > interval[1])
		handle_outside_interval(data, interval);
	else
		handle_within_interval(data);
	free(interval);
}
