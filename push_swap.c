/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:57:22 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 03:38:10 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	t_swap	my_swap;

	if (ac <= 1)
		exit(0);
	my_swap.len = ft_len(av);
	my_swap.tab = malloc(my_swap.len * sizeof(long));
	my_swap.s_tab = malloc(my_swap.len * sizeof(long));
	check_isdigit(&my_swap, av);
	check_eroor(&my_swap);
	ft_inisialiser(&my_swap);
	if (my_swap.len == 3)
		sort_tree(&my_swap);
	else if (my_swap.len == 5)
		sort_five(&my_swap);
	else
		ft_stock_tab(&my_swap);
	free(my_swap.tab);
	free(my_swap.s_tab);
	return (0);
}
