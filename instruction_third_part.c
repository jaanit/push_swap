/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_third_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:58:17 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/27 21:46:25 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rotate_a(t_swap *my_swap, int bool)
{
	int		temp;
	int		i;

	i = my_swap->top_a;
	temp = my_swap->tab[my_swap->top_a];
	while (i < my_swap->index)
	{
		my_swap->tab[i] = my_swap->tab[i + 1];
		i++;
	}
	my_swap->tab[my_swap->index] = temp;
	if (bool == 1)
		write(1, "ra\n", 3);
}

void	ft_rotate_b(t_swap *my_swap, int bool)
{
	int		temp;
	int		i;

	i = my_swap->top_b;
	temp = my_swap->tab[my_swap->top_b];
	while (i > 0)
	{
		my_swap->tab[i] = my_swap->tab[i - 1];
		i--;
	}
	my_swap->tab[0] = temp;
	if (bool == 1)
		write(1, "rb\n", 3);
}

void	ft_ra_rb(t_swap *my_swap, int bool)
{
	ft_rotate_a(my_swap, 0);
	ft_rotate_b(my_swap, 0);
	if (bool == 1)
		write(1, "rr\n", 3);
}
