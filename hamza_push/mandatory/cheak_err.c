/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:17 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/17 22:41:00 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-')
		return (1);
	return (0);
}

int	cheak_nbr(char *ar)
{
	int	i;

	i = -1;
	while (ar[++i])
	{
		if (!ft_isdigit(ar[i]))
			return (0);
	}
	return (1);
}

int	cheak_err(char *av[])
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!cheak_nbr(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	cheak_err_doubl(t_stake **A)
{
	t_stake	*new;
	t_stake	*old;

	old = *A;
	while (old->next)
	{
		new = *A;
		while (new)
		{
			if (new->nbr == old->nbr && new->index != old->index)
				return (0);
			new = new->next;
		}
		old = old->next;
	}
	return (1);
}
