/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_groups.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 00:09:55 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 01:30:19 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fillgroupes(int **groupes, int size, int min, int max)
{
	int	i;

	i = 1;
	if (size >= 1)
	{
		groupes[i][0] = min;
		groupes[i][1] = groupes[i][0] + (max - min) / size;
		i++;
	}
	if (size >= 2)
	{
		groupes[i][0] = 1 + groupes[i - 1][1];
		groupes[i][1] = groupes[i][0] + (max - min) / size;
		i++;
	}
	if (size >= 3)
	{
		groupes[i][0] = 1 + groupes[i - 1][1];
		groupes[i][1] = max;
	}
}

int	**get_created_groupes(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;
	int	min;
	int	max;
	int	**groupes;

	i = 0;
	min = getmin(stack_a);
	max = getmax(stack_a);
	groupes = (int **)malloc(sizeof(int *) * (size + 1));
	if (!groupes)
		handle_error(stack_a, stack_b);
	groupes[0] = (int *)malloc(sizeof(int));
	if (!groupes[0])
		handle_error(stack_a, stack_b);
	groupes[i][0] = size;
	while (++i <= size)
	{
		groupes[i] = (int *)malloc(sizeof(int) * 2);
		if (!groupes)
			handle_error(stack_a, stack_b);
	}
	fillgroupes(groupes, size, min, max);
	return (groupes);
}

void	reverse_rotate_stacks(t_stack *a, t_stack *b, int items[2],
		int places[2])
{
	while (places[0] <= (b->size - 1) / 2 && b->values[b->size - 1] != items[0]
		&& places[1] <= (a->size - 1) / 2 && a->values[0] != items[1])
		(void)(rrr(a, b) && ft_putstr_fd("rrr\n", 1));
	while (places[0] <= (b->size - 1) / 2 && b->values[b->size - 1] != items[0])
		(void)(rrb(b) && ft_putstr_fd("rrb\n", 1));
	while (places[1] <= (a->size - 1) / 2 && a->values[0] != items[1])
		(void)(rra(a) && ft_putstr_fd("rra\n", 1));
}

void	rotate_stacks(t_stack *a, t_stack *b, int items[2], int places[2])
{
	while (places[0] > (b->size - 1) / 2 && b->values[b->size - 1] != items[0]
		&& places[1] > (a->size - 1) / 2 && a->values[0] != items[1])
		(void)(rr(a, b) && ft_putstr_fd("rr\n", 1));
	while (places[0] > (b->size - 1) / 2 && b->values[b->size - 1] != items[0])
		(void)(rb(b) && ft_putstr_fd("rb\n", 1));
	while (places[1] > (a->size - 1) / 2 && a->values[0] != items[1])
		(void)(ra(a) && ft_putstr_fd("ra\n", 1));
}

void	push_groupes(t_stack *stack_a, t_stack *stack_b, int *groupe)
{
	int	value;
	int	index;

	while (stack_a->size > 2 && is_ingroup(stack_a, groupe))
	{
		index = get_member_to_push(stack_a, groupe);
		value = stack_a->values[index];
		while (index > (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != value)
			(void)(ra(stack_a) && ft_putstr_fd("ra\n", 1));
		while (index <= (stack_a->size - 1) / 2
			&& stack_a->values[stack_a->size - 1] != value)
			(void)(rra(stack_a) && ft_putstr_fd("rra\n", 1));
		(void)(pb(stack_a, stack_b) && ft_putstr_fd("pb\n", 1));
	}
}
