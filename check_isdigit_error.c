/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isdigit_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 03:52:17 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 03:52:17 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_isdigit(t_swap *my_swap, char **av)
{
	int		j;
	int		i;
	int		t;
	int		x ;

	i = 0;
	t = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
				print_error();
		}
	x = -1;
		if (!(check_space(av[i])))
		{	
			my_swap->temp = ft_split(av[i], ' ');
			while (my_swap->temp[++x])
				my_swap->tab[t++] = ft_atoi(my_swap->temp[x]);
		}
		else
			my_swap->tab[t++] = ft_atoi(av[i]);
	}
}

void	check_eroor(t_swap *my_swap)
{
	int		i;
	int		j;

	i = 0;
	while (i < my_swap->len)
	{
		if (my_swap->tab[i] > 2147483647 || my_swap->tab[i] < -2147483648)
			print_error();
	j = i + 1;
		while (j < my_swap->len)
		{
			if (my_swap->tab[i] == my_swap->tab[j])
				print_error();
			j++;
		}
	i++;
	}
}

int	ft_isdigit(int str)
{
	if ((str >= '0' && str <= '9') || str == '-' || str == '+')
		return (1);
	return (0);
}

long	ft_atoi(const char *s)
{
	int		i;
	long	result;
	int		n;
	char	*str;

	n = 1;
	i = 0;
	result = 0;
	str = (char *)s;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		n = (n * -1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10);
		result = result + str[i] - 48;
			i++;
	}
	return (result * n);
}
