/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big_nbrs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:33:46 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/18 19:43:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

/* simply returns the index of the number which is closest to top of pile A */

static int	rtn_number_index(int dist_up, int dist_down,
	int from_bottom, t_data *data)
{
	if (dist_up <= dist_down)
		return (data->pile_a[dist_up]);
	else
		return (data->pile_a[from_bottom]);
}

/* scan number returns the first number from the index which pertains
to the chunk and which is the closest from the top of pile a */

static int	scan_number(t_data *data, int index_start, int index_end)
{
	int			dist_up;
	int			dist_down;
	int			from_bottom;

	dist_up = 0;
	dist_down = 0;
	from_bottom = data->size_a - 1;
	while (dist_up < data->size_a)
	{
		if (get_sorted_pos(data, data->pile_a[dist_up]) >= index_start
			&& get_sorted_pos(data, data->pile_a[dist_up]) <= index_end)
			break ;
		dist_up++;
	}
	while (from_bottom >= 0)
	{
		if (get_sorted_pos(data, data->pile_a[from_bottom]) >= index_start
			&& get_sorted_pos(data, data->pile_a[from_bottom]) <= index_end)
			break ;
		dist_down++;
		from_bottom--;
	}
	return (rtn_number_index(dist_up, dist_down, from_bottom, data));
}

/* choose num to push to top of pile A, then push it the most efficient way,
then reorganize pile B  */

static void	process_chunk(t_data *data, int chunk_len,
	int index_start, int index_end)
{	
	int		num_to_push_up;

	while (chunk_len > 0)
	{
		num_to_push_up = scan_number(data, index_start, index_end);
		push_to_top_pile(data, num_to_push_up, ALPHA);
		organize_pile_bravo(data);
		chunk_len--;
	}
}

/* for big numbers ( > 5), we won't use the same numbers of reps
to sort pile A. So calc_chunk_num return the num of reps,
depending of the size of pile A */

static int	calc_chunk_num(t_data *data)
{
	if (data->stack_size <= 20)
		return (1);
	else if (data->stack_size > 20 && data->stack_size <= 40)
		return (2);
	else if (data->stack_size > 40 && data->stack_size <= 60)
		return (3);
	else if (data->stack_size > 60 && data->stack_size <= 99)
		return (4);
	else if (data->stack_size >= 100 && data->stack_size < 500)
		return (5);
	else
		return (11);
}

/* used for big nums ( > 5)
reps is the number of repetitions of the loop
chunk len is the size of every chunk 
index_start and index_end are the indexes of first and last index 
of a given chunk */

void	algo_big_nums(t_data *data)
{
	int		reps;
	int		index_start;
	int		index_end;
	int		chunk_len;
	int		last_chunk;

	data->pile_begin = int_arr_dup(data->pile_a, data->size_a);
	if (!data->pile_begin)
		free_stacks_and_exit(data);
	reps = calc_chunk_num(data);
	chunk_len = data->stack_size / reps;
	last_chunk = data->stack_size % reps;
	index_start = 0;
	index_end = chunk_len - 1;
	while (reps > 0)
	{
		process_chunk(data, chunk_len, index_start, index_end);
		index_start += chunk_len;
		index_end += chunk_len;
		reps--;
	}
	if (last_chunk != 0)
		process_chunk(data, last_chunk, index_start,
			(index_end + last_chunk - 1));
	empty_pile_bravo(data);
}
