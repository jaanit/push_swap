/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 05:42:15 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/25 05:42:17 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s_tab(t_swap *my_swap)
{
	int		i;
	int		j;
	int		len;

	i = my_swap->top_a;
	j = 0;
	len = 0;
	while (len < my_swap->count_a)
	{
		my_swap->s_tab[j++] = my_swap->tab[i++];
		len++;
	}
	i = 0;
	while (i < my_swap->count_a)
	{
		j = i + 1;
		while (j < my_swap->count_a)
		{
			if (my_swap->s_tab[i] > my_swap->s_tab[j])
				ft_swap(&my_swap->s_tab[i], &my_swap->s_tab[j]);
			j++;
		}
		i++;
	}
}

int	ft_check_tab(t_swap *my_swap, long n)
{
	int		i;

	i = my_swap->top_a;
	while (my_swap->count_a)
	{
		if (my_swap->tab[i] <= n)
			return (0);
		i++;
	}
	return (1);
}

int	chek_max_tab(t_swap *my_swap)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (j <= my_swap->top_b)
	{
		if (my_swap->tab[i] < my_swap->tab[j])
			i = j;
		j++;
	}
	return (i);
}
