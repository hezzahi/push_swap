/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:37:52 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/04/15 14:13:01 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sous_finish_class(t_stake **A)
{
	t_stake	*tmp;

	tmp = *A;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->nbr == (*A)->nbr)
	{
		if (tmp->nbr == (*A)->nbr)
			rra(A);
		tmp = *A;
		while (tmp->next)
			tmp = tmp->next;
	}
	free (tmp);
}

void	finich_class(t_stake **A, t_stake **B)
{
	int		c;
	int		d;

	c = min_a(A);
	if (c <= (len(A) / 2))
	{
		while (c--)
			ra(A);
	}	
	else
	{
		d = len(A) - c;
		while (d--)
			rra(A);
	}
	if (!comme_true(A))
		sous_finish_class(A);
	indx_lst(A, B);
}

void	push_swap_aid(t_stake **A, t_stake **B)
{
	pucher(A, B);
	while (1)
	{
		nbr_move(A, B);
		if (!(*B))
			break ;
	}
	if (!comme_true(A))
		finich_class(A, B);
}

void	push_swap(int ac, char *av[])
{
	t_stake	*stack_a;
	t_stake	*stack_b;

	stack_a = NULL;
	if (ac > 1 && cheak_err(av))
	{
		stack_a = lis(av, stack_a);
		stack_b = NULL;
		if (cheak_err_doubl(&stack_a))
		{
			if (!comme_true(&stack_a))
			{
				if (size_lst(&stack_a) <= 5)
					min_push_swap(&stack_a, &stack_b);
				else
					push_swap_aid(&stack_a, &stack_b);
			}
		}
		else
			write(1, "Error", 5);
	}
	else
		write(1, "Error", 5);
}

int	main(int ac, char *av[])
{
	push_swap(ac, av);
}
