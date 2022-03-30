/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_second_part.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 02:42:07 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 03:55:21 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	reverse_rotate_a(t_swap *my_swap, int bool)
{
	int		i;
	int		j;
	int		temp;

	j = my_swap->index;
	i = my_swap->top_a;
	temp = my_swap->tab[j];
	while (j > i)
	{
		my_swap->tab[j] = my_swap->tab[j - 1];
		j--;
	}
	my_swap->tab[my_swap->top_a] = temp;
	if (bool == 1)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_swap *my_swap, int bool)
{
	int		i;
	int		j;
	int		temp;

	if (my_swap->top_b > 1)
	{
		i = my_swap->top_b;
		j = 0;
		temp = my_swap->tab[0];
		while (j < my_swap->top_b)
		{
			my_swap->tab[j] = my_swap->tab[j + 1];
			j++;
		}
		my_swap->tab[my_swap->top_b] = temp;
		if (bool == 1)
			write(1, "rrb\n", 4);
	}
}

void	ft_rrr(t_swap *my_swap, int bool)
{
	reverse_rotate_a(my_swap, 0);
	reverse_rotate_b(my_swap, 0);
	if (bool == 1)
		write(1, "rrr\n", 4);
}

void	ft_push_b(t_swap *my_swap, int bool)
{
	my_swap->top_a++;
	my_swap->count_a--;
	my_swap->top_b++ ;
	if (bool == 1)
		write(1, "pb\n", 3);
}

void	ft_push_a(t_swap *my_swap, int bool)
{
	if (my_swap->top_b >= 0)
	{
		my_swap->top_a--;
		my_swap->top_b-- ;
		if (bool == 1)
			write(1, "pa\n", 3);
	}
}
