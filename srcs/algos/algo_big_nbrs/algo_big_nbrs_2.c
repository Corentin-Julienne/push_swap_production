/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:56:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 18:01:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/* check if the num in top of pile A is within the interval
composed of the smallest and highest numbers in pile B
if outside of interval (easiest case),
push the smallest number to the top of pile B 
return 0 if inside interval, 1 if not */

static int	handle_case_interval(t_data *data, int num)
{
	int			*interval;
	int			i;

	interval = find_interval(data, BRAVO);
	if (!interval)
		free_stacks_and_exit(data);
	i = 0;
	if (num < interval[0] || num > interval[1])
	{
		while (i < data->size_b)
		{
			if (data->pile_b[i] == interval[0])
			{
				push_to_top_pile(data, interval[0], BRAVO);
				break ;
			}
			i++;
		}
		free(interval);
		interval = NULL;
		return (1);
	}
	free(interval);
	interval = NULL;
	return (0);
}

/* return -1 if no change are to made in pile B order
return the position to put in  the top of pile B if changes are needed */

static int	find_good_pos(t_data *data)
{
	int			target_pos;
	int			gd_num;
	int			diff;
	int			i;

	if (handle_case_interval(data, data->pile_a[0]) == 1)
		return (-1);
	target_pos = get_sorted_pos(data, data->pile_a[0]);
	diff = 0;
	i = 0;
	while (data->pile_b && i < data->size_b)
	{
		if (get_sorted_pos(data, data->pile_b[i]) > target_pos
			&& ((get_sorted_pos(data, data->pile_b[i]) - target_pos) < diff
				|| (diff == 0)))
		{
			diff = get_sorted_pos(data, data->pile_b[i]) - target_pos;
			gd_num = data->pile_b[i];
		}
		i++;
	}
	if (diff == 0 || data->pile_b[0] == gd_num)
		return (-1);
	return (gd_num);
}

/* this function handle what number is needed in top of pile B
to insert the num in top of pile A in a sorted way,
then push this num in top of pile B */

int	organize_pile_bravo(t_data *data)
{	
	int			gd_num;

	if (!data->pile_b || !data->pile_b[0] || !data->pile_b[1])
	{
		pb(data, data->pile_a, data->pile_b);
		return (0);
	}
	gd_num = find_good_pos(data);
	if (gd_num != -1)
		push_to_top_pile(data, gd_num, BRAVO);
	pb(data, data->pile_a, data->pile_b);
	return (0);
}

/* once pile A is empty, we have to find the biggest number in Stack B,
move it to the top, and push it over to Stack A.
Repeat this until Stack B is empty.*/

void	empty_pile_bravo(t_data *data)
{
	int		*interval;

	while (data->size_b > 0)
	{
		if (data->size_b >= 2)
		{
			interval = find_interval(data, BRAVO);
			if (!interval)
				free_stacks_and_exit(data);
			if (interval[1] != data->pile_b[0])
				push_to_top_pile(data, interval[1], BRAVO);
			free(interval);
			interval = NULL;
		}
		pa(data, data->pile_a, data->pile_b);
	}
}
