/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_first_part.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:52:03 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 03:54:55 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_a(t_swap *my_swap, int bool)
{
	int		temp;

	temp = my_swap->tab[my_swap->top_a];
	my_swap->tab[my_swap->top_a] = my_swap->tab[my_swap->top_a + 1];
	my_swap->tab[my_swap->top_a + 1] = temp;
	if (bool == 1)
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_swap *my_swap, int bool)
{
	int		temp;

	if (my_swap->top_b > 0)
	{
		temp = my_swap->tab[my_swap->top_b];
		my_swap->tab[my_swap->top_b] = my_swap->tab[my_swap->top_b + 1];
		my_swap->tab[my_swap->top_b + 1] = temp;
		if (bool == 1)
			write(1, "sb\n", 3);
	}
}

void	ft_sa_sb(t_swap *my_swap, int bool)
{
	ft_swap_a(my_swap, 0);
	ft_swap_b(my_swap, 0);
	if (bool == 1)
		write(1, "ss\n", 3);
}
