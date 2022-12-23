/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:55:14 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 02:13:00 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = stack_a->size - 1;
	if (i > 0)
	{
		tmp = stack_a->values[i];
		while (--i >= 0)
		{
			if (tmp > stack_a->values[i])
				return (0);
			tmp = stack_a->values[i];
		}
	}
	return (b_is_sorted(stack_a, stack_b));
}

void	sort_b(t_stack *stack_b)
{
	int	index;
	int	max;

	if (stack_b->size - 1 > 0)
	{
		max = getmax(stack_b);
		index = stack_b->size - 1;
		while (stack_b->values[index] != max && index >= 0)
			index--;
		while (stack_b->values[stack_b->size - 1] != max && index
			> (stack_b->size - 1) / 2)
			(void)(rb(stack_b) && ft_putstr_fd("rb\n", 1));
		while (stack_b->values[stack_b->size - 1] != max && index
			<= (stack_b->size - 1) / 2)
			(void)(rrb(stack_b) && ft_putstr_fd("rrb\n", 1));
	}
}

void	sort_a(t_stack *stack_a)
{
	int	place;
	int	smallest;

	if (stack_a->size > 1)
	{
		smallest = getmin(stack_a);
		place = stack_a->size - 1;
		while (place >= 0 && stack_a->values[place] != smallest)
			place--;
		while (place > (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != smallest)
			(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
		while (place <= (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != smallest)
			(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
	}
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_a->size > 1 && !is_sorted(stack_a, stack_b))
	{
		if (i == 10)
		{
			exit(0);
			i++;
		}
		if (stack_a->values[stack_a->size - 1] > stack_a->values[stack_a->size
				- 2] && stack_a->values[stack_a->size - 1] > stack_a->values[0])
			(void)(ra(stack_a) & ft_putstr_fd("ra \n", 1));
		else if (stack_a->values[stack_a->size - 2]
			> stack_a->values[stack_a->size - 1]
			&& stack_a->values[stack_a->size - 2] > stack_a->values[0])
			(void)(sa(stack_a) && ra(stack_a) && ft_putstr_fd("sa\nra\n", 1));
		else if (stack_a->values[0] > stack_a->values[stack_a->size - 1]
			&& stack_a->values[0] >= stack_a->values[stack_a->size - 2])
		{
			push_and_rotate_handler(stack_a, stack_b);
		}
	}
	sort_b(stack_b);
	push_allvalues_toa(stack_a, stack_b);
}

void	fullsort(t_stack *stack_a, t_stack *stack_b)
{
	int	**groups;
	int	amount;
	int	i;

	if (stack_a->size < 75)
		amount = 1;
	else if (stack_a->size < 100)
		amount = 2;
	else
		amount = 3;
	groups = get_created_groupes(stack_a, stack_b, amount);
	i = 0;
	while (i <= groups[0][0])
	{
		push_groupes(stack_a, stack_b, groups[i]);
		i++;
	}
	i = groups[0][0];
	while (i > 0)
	{
		push_and_sort_group(stack_a, stack_b, groups[i]);
		free(groups[i--]);
	}
	delete(groups, i);
	sort_a(stack_a);
}
