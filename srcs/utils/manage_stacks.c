/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:36:08 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:29:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* return the sorted postion
(the index of the number if the array if sorted) 
functionnal only for pile A */

int	get_sorted_pos(t_data *data, int num)
{
	int		pos;
	int		*cpy;

	cpy = int_arr_dup(data->pile_begin, data->stack_size);
	if (!cpy)
		free_stacks_and_exit(data);
	quicksort(cpy, 0, data->stack_size - 1);
	pos = 0;
	while (cpy[pos] != num)
		pos++;
	free(cpy);
	return (pos);
}

/* this function calculate if it is quicker to rotate or reverse rotate
to push a given number to the top of the pile */

int	distance_to_top_pile(int value, t_data *data, int a_or_b)
{
	int			pile_size;
	int			dst_from_up;
	int			*pile;

	if (a_or_b == ALPHA)
	{
		pile_size = data->size_a;
		pile = data->pile_a;
	}
	else
	{
		pile_size = data->size_b;
		pile = data->pile_b;
	}
	dst_from_up = 0;
	while (pile && pile[dst_from_up] != value)
		dst_from_up++;
	if (dst_from_up < (pile_size / 2))
		return (UP);
	else
		return (DOWN);
}

/* this function calculate the quickest path to the top pile
for a given number and put it at the top */

void	push_to_top_pile(t_data *data, int num, int pile_id)
{
	if (pile_id == ALPHA
		&& distance_to_top_pile(num, data, ALPHA) == UP)
	{
		while (data->pile_a && data->pile_a[0] != num)
			rab(data, data->pile_a, ALPHA);
	}
	else if (pile_id == ALPHA
		&& distance_to_top_pile(num, data, ALPHA) == DOWN)
	{
		while (data->pile_a && data->pile_a[0] != num)
			rrab(data, data->pile_a, ALPHA);
	}
	else if (pile_id == BRAVO
		&& distance_to_top_pile(num, data, BRAVO) == UP)
	{
		while (data->pile_b && data->pile_b[0] != num)
			rab(data, data->pile_b, BRAVO);
	}
	else if (pile_id == BRAVO
		&& distance_to_top_pile(num, data, BRAVO) == DOWN)
	{
		while (data->pile_b && data->pile_b[0] != num)
			rrab(data, data->pile_b, BRAVO);
	}
}

/*  */

int	distance_from_sorted_pos(int value, t_data *data, int *pile, int a_or_b)
{
	int		pile_size;
	int		dst_from_up;

	if (a_or_b == ALPHA)
		pile_size = data->size_a;
	else
		pile_size = data->size_b;
	dst_from_up = 0;
	while (pile && pile[dst_from_up] != value)
		dst_from_up++;
	if (dst_from_up < (pile_size / 2))
		return (CLOCK);
	else
		return (REVERSE);
}
