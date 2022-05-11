/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_case_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:22 by cjulienn          #+#    #+#             */
/*   Updated: 2022/04/11 18:24:31 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* just swap num 1 and num 2 in pile A. Thats it, really */

void	algo_case_two_nums(t_data *data)
{	
	if (data->pile_a[0] > data->pile_a[1])
		sab(data, ALPHA, data->pile_a);
}
