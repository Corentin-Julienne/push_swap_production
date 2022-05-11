/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:01:15 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:23:30 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*

pa : push a - take the first element at the top of b and put it at the top of a 
Do nothing if B is empty.

pb : push b - take the first element at the top of a and put it at the top of b 
Do nothing if A is empty.

*/

static void	replace_piles(t_data *data, int *updt_a, int *updt_b)
{
	if (data->pile_a)
	{
		free(data->pile_a);
		data->pile_a = NULL;
	}
	if (data->pile_b)
	{
		free(data->pile_b);
		data->pile_b = NULL;
	}
	data->pile_a = updt_a;
	data->pile_b = updt_b;
}

static int	*update_pile_a(t_data *data, int *pile_a, int *pile_b)
{
	int		*updt_a;
	int		i;

	updt_a = (int *)malloc(sizeof(int) * data->size_a);
	if (!updt_a)
		free_stacks_and_exit(data);
	updt_a[0] = pile_b[0];
	i = 1;
	while (i < data->size_a)
	{
		updt_a[i] = pile_a[i - 1];
		i++;
	}
	return (updt_a);
}

static int	*update_pile_b(t_data *data, int *pile_a, int *pile_b)
{
	int		*updt_b;
	int		i;

	updt_b = (int *)malloc(sizeof(int) * data->size_b);
	if (!updt_b)
		free_stacks_and_exit(data);
	updt_b[0] = pile_a[0];
	i = 1;
	while (i < data->size_b)
	{
		updt_b[i] = pile_b[i - 1];
		i++;
	}
	return (updt_b);
}

int	pa(t_data *data, int *pile_a, int *pile_b)
{
	int		*updt_a;
	int		*updt_b;
	int		i;

	if (data->size_b == 0)
		return (1);
	updt_b = NULL;
	data->size_a++;
	updt_a = update_pile_a(data, pile_a, pile_b);
	data->size_b--;
	if (data->size_b > 0)
		updt_b = (int *)malloc(sizeof(int) * data->size_b);
	if (!updt_b && data->size_b > 0)
		free_stacks_and_exit(data);
	i = 0;
	while (i < data->size_b)
	{
		updt_b[i] = pile_b[i + 1];
		i++;
	}
	replace_piles(data, updt_a, updt_b);
	msg_writer(STDOUT_FILENO, "pa\n", data);
	data->counter++;
	return (0);
}

int	pb(t_data *data, int *pile_a, int *pile_b)
{
	int		*updt_b;
	int		*updt_a;
	int		i;

	if (data->size_a == 0)
		return (1);
	updt_a = NULL;
	data->size_b++;
	updt_b = update_pile_b(data, pile_a, pile_b);
	data->size_a--;
	if (data->size_a > 0)
		updt_a = (int *)malloc(sizeof(int) * data->size_a);
	if (!updt_a && data->size_a > 0)
		free_stacks_and_exit(data);
	i = 0;
	while (i < data->size_a)
	{
		updt_a[i] = pile_a[i + 1];
		i++;
	}
	replace_piles(data, updt_a, updt_b);
	msg_writer(STDOUT_FILENO, "pb\n", data);
	data->counter++;
	return (0);
}
