/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:07:27 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:02:07 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define ALPHA		1
# define BRAVO		2
# define COMBINED	3

# define UP			1
# define DOWN		2

# define CLOCK		1
# define REVERSE	2

typedef struct s_data
{
	int				i;
	int				is_sorted;
	int				stack_size;
	int				counter;
	int				*pile_begin;
	int				*pile_a;
	int				*pile_b;
	int				size_a;
	int				size_b;
}					t_data;

/* ACTIONS */

/* push.c */
int			pa(t_data *data, int *pile_a, int *pile_b);
int			pb(t_data *data, int *pile_a, int *pile_b);
/* rotate.c */
int			rrab(t_data *data, int *pile, int a_or_b);
int			rab(t_data *data, int *pile, int a_or_b);
int			rr(t_data *data, int *pile_a, int *pile_b);
int			rrr(t_data *data, int *pile_a, int *pile_b);
/* swap.c */
int			sab(t_data *data, int a_or_b, int *pile);
int			ss(t_data *data, int *pile_a, int *pile_b);

/* ALGOS */

/* algo_big_nbrs_1.c */
void		algo_big_nums(t_data *data);
/* algo_big_nbrs_2.c */
int			organize_pile_bravo(t_data *data);
void		empty_pile_bravo(t_data *data);
/*algo_case_2.c*/
void		algo_case_two_nums(t_data *data);
/* algo_case_3.c */
void		algo_case_three_nums(t_data *data, int *pile_a);
/* algo_case_4.c */
void		algo_case_four_nums(t_data *data);
void		sort_param_top_b(t_data *data, int *pile_a);
/* algo_case_5.c*/
void		algo_case_five_nums(t_data *data);

/* ARGS PROCESSING */

/* check_args_validity_1.c */
int			*check_args_are_valid(char **input, t_data *data);
/* check_args_validity_2.c */
int			check_if_already_sorted(int *nums, int stack_size);
int			check_if_duplicates(int	*nums, int stack_size);
int			is_int_compatible(const char *str);
/* format_input.c */
char		**format_input(int argc, char **argv, t_data *data);

/* UTILS */

/* free.c */
void		error_and_exit(t_data *data);
void		free_stacks_and_exit(t_data *data);
void		suppress_leaks_bfr_exit(t_data *data);
void		free_split(char **split);
/* interval.c */
void		handle_within_interval(t_data *data);
void		handle_outside_interval(t_data *data, int *interval);
int			*find_interval(t_data *data, int a_or_b);
/* manage_stacks.c */
int			get_sorted_pos(t_data *data, int num);
int			distance_to_top_pile(int value, t_data *data, int a_or_b);
void		push_to_top_pile(t_data *data, int num, int pile_id);
int			distance_from_sorted_pos(int value, t_data *data,
				int *pile, int a_or_b);
/* quicksort.c */
void		ft_swap(int *a, int *b);
int			*int_arr_dup(int *to_cpy, int arr_size);
int			are_arr_equals(int *arr_a, int *arr_b, int arr_size);
void		quicksort(int *nums, int begin, int end);

/* FILE CONTAINING MAIN */

/* push_swap.c */
void		msg_writer(int fildes, char *msg, t_data *data);

#endif
