/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_validity_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:26:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:21:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* check if every int is within int range */

static int	check_int_limits(const char *ptn, int sign)
{
	char				*str;
	unsigned long long	res;
	long long			res_with_sign;

	str = (char *)ptn;
	res = 0;
	if ((ft_strlen(str) == 1 && sign == -1 && str[0] == 48)
		|| (ft_strlen(str) > 1 && str[0] == 48) || ft_strlen(str) > 10)
		return (1);
	while (str[0])
	{
		if (str[0] >= '0' && str[0] <= '9')
			res = (res * 10) + (str[0] - '0');
		else
			break ;
		str++;
	}
	res_with_sign = sign * res;
	if (res_with_sign > INT_MAX || res_with_sign < INT_MIN)
		return (1);
	return (0);
}

/* compare the arr to a quiksorted copy of this arr. Check if they are equals
return 0 if they are different, 1 arr already sorted,
and -1 in case of malloc error */

int	check_if_already_sorted(int *nums_input, int stack_size)
{
	int			*nums_dupl;

	nums_dupl = int_arr_dup(nums_input, stack_size);
	if (!nums_dupl)
		return (-1);
	quicksort(nums_dupl, 0, stack_size - 1);
	if (are_arr_equals(nums_input, nums_dupl, stack_size) == 1)
	{
		free(nums_dupl);
		return (1);
	}
	free(nums_dupl);
	return (0);
}

/* check every int within int arr has no duplicates */

int	check_if_duplicates(int	*nums, int stack_size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < stack_size)
	{
		while (i < stack_size)
		{
			if (nums[j] == nums[i] && j != i)
				return (1);
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}

/* check if is a number (verify if within int range in the next function) */

int	is_int_compatible(const char *str)
{
	char	*ptn;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	ptn = (char *)str;
	if (ptn[0] == '-')
	{
		sign = -1;
		ptn++;
	}
	while (ptn[i])
	{
		if (ptn[i] < 48 || ptn[i] > 58)
			return (1);
		i++;
	}
	return (check_int_limits(ptn, sign));
}
