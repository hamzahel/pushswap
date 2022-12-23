/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:30:43 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 01:45:57 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	i;
	int	max;
	int	min;

	i = stack_b->size - 1;
	tmp = stack_b->values[i];
	max = getmax(stack_b);
	min = getmin(stack_b);
	if (i >= 0)
	{
		while (--i > 0)
		{
			if (tmp < stack_b->values[i] && min != tmp)
				return (0);
			tmp = stack_a->values[i];
		}
		if (stack_a->size > 0 && max > stack_a->values[stack_a->size - 1])
		{
			push_to_a(stack_a, stack_b);
		}
	}
	return (1);
}

void	move_index(t_stack *stack_b, int index, int value)
{
	while ((stack_b->size - 1) / 2 < index && value != stack_b->values[0])
	{
		(void)(rb(stack_b) && ft_putstr_fd("rb\n", 1));
	}
	while ((stack_b->size - 1) / 2 >= index && value != stack_b->values[0])
	{
		(void)(rrb(stack_b) && ft_putstr_fd("rrb\n", 1));
	}
}

void	push_rotate_to_top_b(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	min;
	int	max;

	if (stack_b->size > 1)
	{
		index = stack_b->size - 1;
		min = getmin(stack_b);
		max = getmax(stack_b);
		while (stack_a->values[stack_a->size - 1] < max
			&& stack_a->values[stack_a->size - 1] > min && index
			> 0 && (stack_b->values[index]
				< stack_a->values[stack_a->size - 1]
				|| stack_b->values[index - 1]
				> stack_a->values[stack_a->size - 1]))
			index--;
		while ((stack_a->values[stack_a->size - 1] > max
				|| stack_a->values[stack_a->size - 1] < min) && index >= 0
			&& stack_b->values[index] != min)
			index--;
		move_index(stack_b, index, stack_b->values[index]);
	}
	(void)(pb(stack_a, stack_b) && ft_putstr_fd("pb\n", 1));
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	sort_b(stack_b);
	while (stack_a->size > 1 && stack_a->values[stack_a->size - 1]
		< stack_b->values[stack_b->size - 1])
		(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
	while (stack_b->size > 0 && stack_b->values[stack_b->size - 1]
		> stack_a->values[0])
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	min = getmin(stack_a);
	while (min != stack_a->values[stack_a->size - 1])
		(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
}

void	push_and_sort_group(t_stack *stack_a, t_stack *stack_b, int *group)
{
	int	items[2];
	int	places[2];
	int	min;
	int	max;

	while (is_ingroup(stack_b, group))
	{
		min = getmin(stack_a);
		max = getmax(stack_a);
		places[0] = get_member_to_push_and_sort(stack_a, stack_b, group);
		items[0] = stack_b->values[places[0]];
		places[1] = stack_a->size - 1;
		while (items[0] > min && items[0] < max && places[1] > 0
			&& (items[0] < stack_a->values[places[1]]
				|| items[0] > stack_a->values[places[1] - 1]))
			places[1]--;
		while ((items[0] < min || items[0] > max) && places[1] >= 0
			&& stack_a->values[places[1]] != max)
			places[1]--;
		items[1] = stack_a->values[places[1]];
		rotate_stacks(stack_a, stack_b, items, places);
		reverse_rotate_stacks(stack_a, stack_b, items, places);
		(void)(pa(stack_a, stack_b) && ft_putstr_fd("pa\n", 1));
	}
}
