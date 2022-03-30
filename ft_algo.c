/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 23:32:35 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/24 03:53:41 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_tree(t_swap *my_swap)
{
	int		x;

	x = my_swap->top_a;
	if (my_swap->tab[x + 2] < my_swap->tab[x + 1]
		&& my_swap->tab[x + 2] < my_swap->tab[x])
	{
		if (my_swap->tab[x] > my_swap->tab[x + 1])
			ft_swap_a(my_swap, 1);
		reverse_rotate_a(my_swap, 1);
	}
	else if ((my_swap->tab[x] < my_swap->tab[x + 1])
		&& (my_swap->tab[x] < my_swap->tab[x + 2])
		&& (my_swap->tab[x + 2] < my_swap->tab[x + 1]))
	{
		ft_swap_a(my_swap, 1);
		ft_rotate_a(my_swap, 1);
	}
	else if ((my_swap->tab[x] > my_swap->tab[x + 1])
		&& (my_swap->tab[x] < my_swap->tab[x + 2]))
		ft_swap_a(my_swap, 1);
	else if ((my_swap->tab[x + 2] < my_swap->tab[x])
		&& (my_swap->tab[x + 1] < my_swap->tab[x + 2]))
		ft_rotate_a(my_swap, 1);
}

int	chek_min_tab(t_swap *my_swap)
{
	int		i;
	int		j;

	i = my_swap->top_a;
	j = i + 1;
	while (j < my_swap->len)
	{
		if (my_swap->tab[i] > my_swap->tab[j])
			i = j;
		j++;
	}
	return (i);
}

void	push_min(t_swap *my_swap)
{
	int		index;
	int		half;

	half = my_swap->count_a / 2;
	index = chek_min_tab(my_swap);
	if (index <= half)
	{
		while (index > my_swap->top_a)
		{
			ft_rotate_a(my_swap, 1);
		index--;
		}
		ft_push_b(my_swap, 1);
	}
	else if (index > half)
	{
		while (index < my_swap->len)
		{
			reverse_rotate_a(my_swap, 1);
		index++;
		}
		ft_push_b(my_swap, 1);
	}
}

void	sort_five(t_swap *my_swap)
{
	push_min(my_swap);
	push_min(my_swap);
	sort_tree(my_swap);
	ft_push_a(my_swap, 1);
	ft_push_a(my_swap, 1);
}
