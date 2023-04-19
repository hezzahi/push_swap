/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:00:32 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/04/15 14:22:46 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_ret(char **ret)
{
	int	i;

	i = -1;
	while (ret[++i])
		free(ret[i]);
	free(ret[i]);
}

int	cheak_err(char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && \
				(av[i][j] != ' ' && av[i][j] != '-'))
				return (0);
		}
	}
	return (1);
}

void	fill_stack_a(char *av[], t_stack **stack_a)
{
	t_stack	*new;
	char	**ret;
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		ret = ft_split(av[i], ' ');
		j = -1;
		while (ret[++j])
		{
			new = lst_new(ret[j]);
			lst_add_back(stack_a, new);
		}
		free_ret(ret);
	}
}
