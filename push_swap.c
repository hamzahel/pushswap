/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ayac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:28:42 by hel-ayac          #+#    #+#             */
/*   Updated: 2021/12/14 19:25:32 by hel-ayac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = putargstostack(stack_a, argv, argc);
		stack_b = init_b(stack_a, stack_b);
		if (stack_a->size < 20)
			quicksort(stack_a, stack_b);
		else
			fullsort(stack_a, stack_b);
	}
	return (0);
}
