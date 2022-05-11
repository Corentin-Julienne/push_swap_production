/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:41:57 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/19 12:16:36 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* this algo push the first two nums on pile B,
then apply algo for three nums on pile A
(if not sorted already), then handle pile B */

void	algo_case_five_nums(t_data *data)
{
	int		*interval;

	interval = find_interval(data, ALPHA);
	if (!interval)
		free_stacks_and_exit(data);
	push_to_top_pile(data, interval[0], ALPHA);
	pb(data, data->pile_a, data->pile_b);
	push_to_top_pile(data, interval[1], ALPHA);
	free(interval);
	pb(data, data->pile_a, data->pile_b);
	algo_case_three_nums(data, data->pile_a);
	pa(data, data->pile_a, data->pile_b);
	rab(data, data->pile_a, ALPHA);
	pa(data, data->pile_a, data->pile_b);
}
