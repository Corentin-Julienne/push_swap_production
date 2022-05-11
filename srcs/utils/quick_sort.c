/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:51:25 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:28:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *nums, int begin, int end)
{
	int		pivot;
	int		i;
	int		j;

	pivot = nums[end];
	i = begin - 1;
	j = begin;
	while (j <= (end - 1))
	{
		if (nums[j] < pivot)
		{
			i++;
			ft_swap(&nums[i], &nums[j]);
		}
		j++;
	}
	ft_swap(&nums[i + 1], &nums[end]);
	return (i + 1);
}

/* an strdup-like function for int arrays */

int	*int_arr_dup(int *to_cpy, int arr_size)
{
	int		*dup;
	int		i;

	dup = (int *)malloc(sizeof(int) * arr_size);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < arr_size)
	{
		dup[i] = to_cpy[i];
		i++;
	}
	return (dup);
}

/* return 1 if arr equals, 0 if not */

int	are_arr_equals(int *arr_a, int *arr_b, int arr_size)
{
	int		i;
	int		diff;

	diff = 0;
	i = 0;
	while (i < arr_size)
	{
		if (arr_a[i] != arr_b[i])
			diff++;
		i++;
	}
	if (diff == 0)
		return (1);
	return (0);
}

/* implement a quicksort in order to check if arr is sorted or not
by comparing a quicksorted copy and the original
(using are_arr_equals function) */

void	quicksort(int *nums, int begin, int end)
{
	int		index;

	if (begin < end)
	{
		index = partition(nums, begin, end);
		quicksort(nums, begin, index - 1);
		quicksort(nums, index + 1, end);
	}
}
