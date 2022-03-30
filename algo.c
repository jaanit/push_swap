/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100and500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 00:29:44 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/27 21:50:29 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_instock_tab(t_swap *my_swap)
{
	if (my_swap->tab[my_swap->top_a] <= my_swap->s_tab[my_swap->multi])
		ft_push_b(my_swap, 1);
	else if ((my_swap->tab[my_swap->top_a] > my_swap->s_tab[my_swap->multi])
		&& (my_swap->tab[my_swap->top_b] <= my_swap->s_tab[my_swap->div])
		&& (my_swap->top_b > 0))
		ft_ra_rb(my_swap, 1);
	else if ((my_swap->tab[my_swap->top_b] <= my_swap->s_tab[my_swap->div])
		&& my_swap->top_b > 0)
		ft_rotate_b(my_swap, 1);
	else if (my_swap->tab[my_swap->top_a] > my_swap->s_tab[my_swap->multi])
		ft_rotate_a(my_swap, 1);
}

void	ft_insort(t_swap *my_swap, int index, int bool)
{
	if (bool == 0)
	{
		while (index < my_swap->top_b)
		{
			ft_rotate_b(my_swap, 1);
				index++;
		}
		ft_push_a(my_swap, 1);
		if (my_swap->tab[my_swap->top_a] > my_swap->tab[my_swap->top_a + 1])
			ft_swap_a(my_swap, 1);
	}
	if (bool == 1)
	{
		while (index >= 0)
		{
			reverse_rotate_b(my_swap, 1);
			index--;
		}
		ft_push_a(my_swap, 1);
		if (my_swap->tab[my_swap->top_a] > my_swap->tab[my_swap->top_a + 1])
			ft_swap_a(my_swap, 1);
	}
}

void	ft_sort_algo(t_swap *my_swap)
{
	int		index;
	int		i;
	int		len;

	i = 0;
	len = my_swap->top_a;
	while (i < len)
	{
		index = chek_max_tab(my_swap);
		my_swap->half = my_swap->top_a / 2;
		if (index > my_swap->half)
			ft_insort(my_swap, index, 0);
		else if (index <= my_swap->half)
			ft_insort(my_swap, index, 1);
		i++;
	}
}

void	ft_stock_tab(t_swap *my_swap)
{
	int		i;

	while (my_swap->top_a < my_swap->index)
	{
		i = my_swap->count_a;
		if (my_swap->len == 100)
			my_swap->multi = my_swap->count_a / 3;
		else
			my_swap->multi = my_swap->count_a / 5;
		my_swap->div = my_swap->multi / 2;
		ft_s_tab(my_swap);
		while (i > 0)
		{
			if (ft_check_tab(my_swap, my_swap->s_tab[my_swap->multi]))
				break ;
			ft_instock_tab(my_swap);
			i--;
		}
	}
	ft_sort_algo(my_swap);
}
