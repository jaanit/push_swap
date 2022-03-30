/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 20:25:21 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 04:40:37 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_checker(t_swap *my_swap, char *line)
{
	if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		ft_push_b(my_swap, 0);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		ft_push_a(my_swap, 0);
	else if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		ft_swap_a(my_swap, 0);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		ft_swap_b(my_swap, 0);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ft_sa_sb(my_swap, 0);
	else if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ft_rotate_a(my_swap, 0);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		ft_rotate_b(my_swap, 0);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ft_ra_rb(my_swap, 0);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		reverse_rotate_a(my_swap, 0);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		reverse_rotate_b(my_swap, 0);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		ft_rrr(my_swap, 0);
	else
		print_error();
}

void	ft_read(t_swap *my_swap)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_checker(my_swap, str);
		free(str);
		str = get_next_line(0);
	}
}

int	check_sorted(t_swap *my_swap)
{
	int		i;
	int		j;

	i = my_swap->top_a;
	while (i < my_swap->len)
	{
		j = i + 1;
		while (j < my_swap->len)
		{
			if (my_swap->tab[i] < my_swap->tab[j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_swap	my_swap;

	if (ac <= 1)
		exit(0);
	my_swap.len = ft_len(av);
	my_swap.tab = malloc(my_swap.len * sizeof(long));
	my_swap.s_tab = malloc(my_swap.len * sizeof(long));
	ft_inisialiser(&my_swap);
	check_isdigit(&my_swap, av);
	check_eroor(&my_swap);
	ft_read(&my_swap);
	if (check_sorted(&my_swap) && my_swap.top_b < 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
