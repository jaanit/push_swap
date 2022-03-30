/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 03:05:24 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 04:09:29 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(long *tab1, long *tab2)
{
	int		temp;

	temp = *tab1;
	*tab1 = *tab2;
	*tab2 = temp;
}

int	ft_len(char **av)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (ft_isdigit(av[i][j]) && (!ft_isdigit(av[i][j + 1])))
				len++;
		}
	}
	return (len);
}

int	check_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_inisialiser(t_swap *my_swap)
{
	my_swap->last_b = my_swap->len - 1;
	my_swap->last_a = my_swap->len;
	my_swap->index = my_swap->len - 1;
	my_swap->count_a = my_swap->len ;
	my_swap->top_a = 0;
	my_swap->top_b = -1;
	my_swap->las_s = my_swap->len - my_swap->top_a;
}
