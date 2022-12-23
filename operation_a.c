/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:46:17 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/14 19:24:03 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkchars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		{
			ft_putstr_fd("Error", 1);
			exit(0);
		}
		if ((str[i] < 48 || str[i] > 57) && str[i] != 45 && str[i] != 43)
		{
			ft_putstr_fd("Error", 1);
			exit(1);
		}
		i++;
	}
}

int	sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size - 1 < 1)
		return (0);
	tmp = stack_a->values[stack_a->size - 1];
	stack_a->values[stack_a->size - 1] = stack_a->values[stack_a->size - 2];
	stack_a->values[stack_a->size - 2] = tmp;
	return (1);
}

int	ra(t_stack *stack_a)
{
	return (shifttop(stack_a));
}

int	rra(t_stack *stack_a)
{
	return (shiftbottom(stack_a));
}

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL)
		handle_error(stack_a, stack_b);
	if (stack_b->size - 1 < 0)
		return (0);
	stack_a->values[stack_a->size] = stack_b->values[stack_b->size - 1];
	stack_a->size++;
	stack_b->size--;
	return (1);
}
