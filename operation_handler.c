/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:51:10 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 02:16:14 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shiftbottom(t_stack *stack)
{
	int	bottom;
	int	i;

	bottom = stack->values[0];
	i = 0;
	if (stack->size - 1 <= 0)
		return (0);
	while (i <= stack->size - 1)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[stack->size - 1] = bottom;
	return (1);
}

int	shifttop(t_stack *stack)
{
	int	top;
	int	i;

	top = stack->values[stack->size - 1];
	i = stack->size - 1;
	if (i <= 0)
		return (0);
	while (i >= 0)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[0] = top;
	return (1);
}

void	delete(int **groups, int i)
{
	free(groups[i]);
	free(groups);
}

int	calcfirst(int index, int size, int isa)
{
	if (index > ((size - 1) / 2))
		return (size - index);
	return (index + isa);
}

void	push_and_rotate_handler(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->values[stack_a->size - 1]
		< stack_a->values[stack_a->size - 2]
		&& stack_a->values[stack_a->size - 1] < stack_a->values[0])
		push_rotate_to_top_b(stack_a, stack_b);
	else if (stack_a->values[stack_a->size - 2]
		< stack_a->values[stack_a->size - 1]
		&& stack_a->values[stack_a->size - 2] <= stack_a->values[0])
		(void)(sa(stack_a) && ft_putstr_fd("sa\n", 1));
	else if (stack_a->values[0] < stack_a->values[stack_a->size - 1]
		&& stack_a->values[0] < stack_a->values[stack_a->size - 2])
		(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
}
