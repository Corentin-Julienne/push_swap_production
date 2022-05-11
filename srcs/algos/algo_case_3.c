/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 18:30:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* simple algo for three pile_a in the stack */

void	algo_case_three_nums(t_data *data, int *pile_a)
{	
	int		sort_result;

	sort_result = check_if_already_sorted(pile_a, 3);
	if (sort_result == -1)
		free_stacks_and_exit(data);
	else if (sort_result == 1)
		return ;
	if (pile_a[0] > pile_a[1] && pile_a[0] < pile_a[2])
		sab(data, ALPHA, pile_a);
	else if (pile_a[0] > pile_a[1] && pile_a[0] > pile_a[2]
		&& pile_a[1] > pile_a[2])
	{
		sab(data, ALPHA, pile_a);
		rrab(data, pile_a, ALPHA);
	}
	else if (pile_a[0] > pile_a[1] && pile_a[0] > pile_a[2]
		&& pile_a[1] < pile_a[2])
		rab(data, pile_a, ALPHA);
	else if (pile_a[0] < pile_a[1] && pile_a[0] < pile_a[2])
	{
		sab(data, ALPHA, pile_a);
		rab(data, pile_a, ALPHA);
	}
	else if (pile_a[0] < pile_a[1] && pile_a[0] > pile_a[2])
		rrab(data, pile_a, ALPHA);
}
