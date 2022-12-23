/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 01:49:01 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/13 01:49:47 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_stack *stack_a, t_stack *stack_b)
{
	return (ra(stack_a) * rb(stack_b));
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	return (sa(stack_a) * sb(stack_b));
}

int	rrr(t_stack *stack_a, t_stack *stack_b)
{
	return (rra(stack_a) * rrb(stack_b));
}
