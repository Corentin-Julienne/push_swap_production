/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:28:05 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/11 13:20:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* calculate the stack size and store it into the data struct */

static void	calc_stack_size(t_data *data, char **input_arr)
{
	int		i;

	data->stack_size = 0;
	i = 0;
	while (input_arr && input_arr[i])
	{
		data->stack_size++;
		i++;
	}
}

/* join the argv data into a single string. args separated by space */

static char	*join_args(char *input, int argc, char **argv, t_data *data)
{
	char	*tmp;
	int		i;

	i = 2;
	while (i < argc)
	{
		tmp = ft_strjoin(input, " ");
		if (!tmp)
		{
			free(input);
			error_and_exit(data);
		}
		free(input);
		input = ft_strjoin(tmp, argv[i]);
		if (!input)
		{
			free(tmp);
			error_and_exit(data);
		}
		free(tmp);
		i++;
	}
	return (input);
}

/* converts the argv data into an arr of strings using split */

char	**format_input(int argc, char **argv, t_data *data)
{
	char	*input;
	char	**input_arr;

	input = ft_strdup(argv[1]);
	if (!input)
		error_and_exit(data);
	input = join_args(input, argc, argv, data);
	input_arr = ft_split(input, ' ');
	if (!input_arr)
	{
		free(input);
		error_and_exit(data);
	}
	calc_stack_size(data, input_arr);
	free(input);
	return (input_arr);
}
