/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:49:01 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 00:09:35 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("Error !", 1);
	free(stack_a);
	free(stack_a->values);
	if (!stack_b)
	{
		free(stack_b);
		free(stack_b->values);
	}
	exit(1);
}

t_stack	*init_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
		handle_error(stack_a, stack_b);
	stack_b->values = malloc(sizeof(int *) * stack_a->res_size);
	if (!stack_b->values)
		handle_error(stack_a, stack_b);
	stack_b->size = 0;
	stack_b->res_size = stack_a->res_size;
	return (stack_b);
}

int	getmax(t_stack *stack)
{
	int	max;
	int	i;

	i = stack->size - 1;
	max = stack->values[i];
	while (i >= 0)
	{
		if (max < stack->values[i])
			max = stack->values[i];
		i--;
	}
	return (max);
}

int	getmin(t_stack *stack)
{
	int	min;
	int	i;

	i = stack->size - 1;
	min = stack->values[i];
	while (i >= 0)
	{
		if (min > stack->values[i])
			min = stack->values[i];
		i--;
	}
	return (min);
}

void	push_allvalues_toa(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;
	if (i == 0)
		return ;
	while (--i >= 0)
	{
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	}
}
