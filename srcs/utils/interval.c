/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:21:25 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:28:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* rotate pile A until data->pile_b inf to data->pile_a,
then push push data->pile_b to data->pile_a,
then use sort_param_top_b to */

void	handle_within_interval(t_data *data)
{
	while (data->pile_b[0] > data->pile_a[0])
		rab(data, data->pile_a, ALPHA);
	pa(data, data->pile_a, data->pile_b);
	sort_param_top_b(data, data->pile_a);
}

/* when outside interval, push num at the top of pile B to top of pile A,
then check if sorted. if not, just rotate the num at the bottom of pile A */

void	handle_outside_interval(t_data *data, int *interval)
{
	pa(data, data->pile_a, data->pile_b);
	if (data->pile_a[0] > interval[0])
		rab(data, data->pile_a, ALPHA);
}

/* find_interval function returns an array of two ints. 
index 0 refers to smallest num in the stack 
while index 1 refers to the  biggest  */

static int	find_biggest(const int *pile, int stack_size)
{
	int		biggest;
	int		i;

	i = 0;
	while (i < stack_size)
	{
		if (i == 0)
		{
			biggest = pile[i];
			if (stack_size >= 2)
				i++;
		}
		if (biggest < pile[i])
			biggest = pile[i];
		i++;
	}
	return (biggest);
}

static int	find_smallest(const int *pile, int stack_size)
{
	int		smallest;
	int		i;

	i = 0;
	while (i < stack_size)
	{
		if (i == 0)
		{
			smallest = pile[i];
			if (stack_size >= 2)
				i++;
		}
		if (smallest > pile[i])
			smallest = pile[i];
		i++;
	}
	return (smallest);
}

int	*find_interval(t_data *data, int a_or_b)
{
	int			*int_arr;
	int			*pile;
	int			stack_size;

	if (a_or_b == ALPHA)
	{
		pile = data->pile_a;
		stack_size = data->size_a;
	}	
	else
	{
		pile = data->pile_b;
		stack_size = data->size_b;
	}
	int_arr = (int *)malloc(sizeof(int) * 2);
	if (!int_arr)
		return (NULL);
	int_arr[0] = find_smallest(pile, stack_size);
	int_arr[1] = find_biggest(pile, stack_size);
	return (int_arr);
}
