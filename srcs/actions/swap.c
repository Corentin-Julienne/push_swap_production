/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:52:01 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 19:26:16 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

sab : is doing either swap a or swap b :
=> sa : swap a - swap the first 2 elements at the top of stack a. 
Do nothing if there is only one or no elements).
=> sb : swap b - swap the first 2 elements at the top of stack b. 
Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

*/

int	sab(t_data *data, int a_or_b, int *pile)
{
	int		num_tmp;
	int		stack_size;

	if (a_or_b == ALPHA)
		stack_size = data->size_a;
	else
		stack_size = data->size_b;
	if (stack_size < 2)
		return (1);
	num_tmp = pile[0];
	pile[0] = pile[1];
	pile[1] = num_tmp;
	if (a_or_b == ALPHA)
		msg_writer(STDOUT_FILENO, "sa\n", data);
	else if (a_or_b == BRAVO)
		msg_writer(STDOUT_FILENO, "sb\n", data);
	if (a_or_b == ALPHA || a_or_b == BRAVO)
		data->counter++;
	return (0);
}

int	ss(t_data *data, int *pile_a, int *pile_b)
{
	int		res_a;
	int		res_b;

	res_a = sab(data, COMBINED, pile_a);
	res_b = sab(data, COMBINED, pile_b);
	if (!res_a || !res_b)
		msg_writer(STDOUT_FILENO, "ss\n", data);
	data->counter++;
	return (0);
}
