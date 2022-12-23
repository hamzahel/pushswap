/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:45:39 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 02:32:08 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ingroup(t_stack	*stack, int	*group)
{
	int	i;

	i = stack->size - 1;
	while (i >= 0)
	{
		if (stack->values[i] >= group[0] && stack->values[i] <= group[1])
			return (1);
		i--;
	}
	return (0);
}

int	getfirst(t_stack *b, t_stack *a, int limits[2], int member)
{
	int	first;
	int	first_a;
	int	place;

	first = calcfirst(member, b->size, 2);
	place = a->size - 1;
	while (b->values[member] > limits[0] && b->values[member] < limits[1]
		&& place > 0 && (b->values[member] < a->values[place]
			|| b->values[member] > a->values[place - 1]))
		place--;
	while ((b->values[member] < limits[0] || b->values[member] > limits[1])
		&& place >= 0 && a->values[place] != limits[1])
		place--;
	first_a = calcfirst(place, a->size, 0);
	if ((member > (b->size - 1) / 2 && place > (a->size - 1) / 2)
		|| (member <= (b->size - 1) / 2 && place <= (a->size - 1) / 2))
		first = getmaxvalue(first, first_a);
	else
		first += first_a;
	return (first);
}

int	get_member_to_push_and_sort(t_stack	*stack_a, t_stack *stack_b, int *group)
{
	int	index;
	int	first[2];
	int	limits[2];
	int	i;

	limits[0] = getmin(stack_a);
	limits[1] = getmax(stack_a);
	i = stack_b->size - 1;
	while (i >= 0 && (stack_b->values[i] < group[0]
			|| stack_b->values[i] > group[1]))
		i--;
	index = i;
	first[0] = getfirst(stack_b, stack_a, limits, index);
	while (--i >= 0)
	{
		first[1] = getfirst(stack_b, stack_a, limits, i);
		if (stack_b->values[i] >= group[0] && stack_b->values[i] <= group[1]
			&& (first[0] > first[1] || (first[0] == first[1]
					&& stack_b->values[index] < stack_b->values[i])))
		{
			index = i;
			first[0] = first[1];
		}
	}
	return (index);
}

int	get_member_to_push(t_stack *stack, int *group)
{	
	int	index;
	int	first;
	int	second;
	int	i;

	i = stack->size - 1;
	while (i >= 0 && (stack->values[i] < group[0]
			|| stack->values[i] > group[1]))
		i--;
	index = i;
	first = calcfirst(index, stack->size, 2);
	while (--i >= 0)
	{
		if (stack->values[i] >= group[0] && stack->values[i] <= group[1])
		{
			second = calcfirst(i, stack->size, 2);
			if (first > second || (first == second
					&& stack->values[index] > stack->values[i]))
			{
				index = i;
				first = second;
			}
		}
	}
	return (index);
}
