/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:49:57 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 02:28:35 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size - 1 < 1)
		return (0);
	tmp = stack_b->values[stack_b->size - 1];
	stack_b->values[stack_b->size - 1] = stack_b->values[stack_b->size - 2];
	stack_b->values[stack_b->size - 2] = tmp;
	return (1);
}

int	rb(t_stack *stack_b)
{
	return (shifttop(stack_b));
}

int	rrb(t_stack *stack_b)
{
	return (shiftbottom(stack_b));
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size - 1 < 0)
		return (0);
	stack_b->values[stack_b->size] = stack_a->values[stack_a->size - 1];
	stack_b->size++;
	stack_a->size--;
	return (1);
}
