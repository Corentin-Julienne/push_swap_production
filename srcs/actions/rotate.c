/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:17 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 19:24:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* 

rrab : doing either rra or rrb
=> rra : reverse rotate a - shift down all elements of stack a by 1. 
The last element becomes the first one.
=> rrb : reverse rotate b - shift down all elements of stack b by 1. 
The last element becomes the first one.

rrr : rra and rrb at the same time.

rab : doing either ra or rb
=> ra : rotate a - shift up all elements of stack a by 1. 
The first element becomes the last one.
=> rb : rotate b - shift up all elements of stack b by 1. 
The first element becomes the last one.

rr : ra and rb at the same time.

*/

static int	rotate_feedback(int direction, int a_or_b, t_data *data)
{
	if (a_or_b == ALPHA && direction == REVERSE)
		msg_writer(STDOUT_FILENO, "rra\n", data);
	else if (a_or_b == BRAVO && direction == REVERSE)
		msg_writer(STDOUT_FILENO, "rrb\n", data);
	else if (a_or_b == ALPHA && direction == CLOCK)
		msg_writer(STDOUT_FILENO, "ra\n", data);
	else if (a_or_b == BRAVO && direction == CLOCK)
		msg_writer(STDOUT_FILENO, "rb\n", data);
	if (a_or_b == ALPHA || a_or_b == BRAVO)
		data->counter++;
	return (0);
}

int	rrab(t_data *data, int *pile, int a_or_b)
{
	int		tmp_last;
	int		last_index;
	int		i;

	if (a_or_b == ALPHA)
		last_index = data->size_a - 1;
	else
		last_index = data->size_b - 1;
	if (last_index < 1)
		return (1);
	tmp_last = pile[last_index];
	i = last_index;
	while (i >= 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = tmp_last;
	return (rotate_feedback(REVERSE, a_or_b, data));
}

int	rab(t_data *data, int *pile, int a_or_b)
{
	int		tmp_first;
	int		stack_size;
	int		i;

	if (a_or_b == ALPHA)
		stack_size = data->size_a;
	else
		stack_size = data->size_b;
	if (stack_size < 2)
		return (1);
	tmp_first = pile[0];
	i = 0;
	while (i < stack_size)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[stack_size - 1] = tmp_first;
	return (rotate_feedback(CLOCK, a_or_b, data));
}

int	rr(t_data *data, int *pile_a, int *pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rab(data, pile_a, COMBINED);
	res_rb = rab(data, pile_b, COMBINED);
	if (!res_ra || !res_rb)
		msg_writer(STDOUT_FILENO, "rr\n", data);
	data->counter++;
	return (0);
}

int	rrr(t_data *data, int *pile_a, int *pile_b)
{
	int		res_ra;
	int		res_rb;

	res_ra = rrab(data, pile_a, COMBINED);
	res_rb = rrab(data, pile_b, COMBINED);
	if (!res_ra || !res_rb)
		msg_writer(STDOUT_FILENO, "rrr\n", data);
	data->counter++;
	return (0);
}
