/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaanit <rjaanit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 04:04:47 by rjaanit           #+#    #+#             */
/*   Updated: 2022/03/30 04:09:01 by rjaanit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

typedef struct my_struct
{	
	long	*tab;
	long	*s_tab;
	char	**tab_sep;
	char	**temp;
	int		len;
	int		last_b;
	int		last_a;	
	int		index;
	int		count;
	int		count_a;
	int		multi;
	int		div;
	int		top_a;
	int		top_b;
	int		las_b;
	int		las_s;
	int		half;
	int		max;

}t_swap;

int		ft_isdigit(int str);
int		ft_len(char **av);
char	*ft_strjoin(char const *s1, char const *s2);
long	ft_atoi(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
int		check_space(char *str);
void	print_error(void);
void	chek_error(char **av);
void	ft_swap(long *tab1, long *tab2);
void	ft_swap_a(t_swap *my_swap, int bool);
void	ft_swap_b(t_swap *my_swap, int bool);
void	ft_sa_sb(t_swap *my_swap, int bool);
void	ft_rotate_a(t_swap *my_swap, int bool);
void	ft_rotate_b(t_swap *my_swap, int bool);
void	ft_ra_rb(t_swap *my_swap, int bool);
void	reverse_rotate_a(t_swap *my_swap, int bool);
void	reverse_rotate_b(t_swap *my_swap, int bool);
void	ft_rrr(t_swap *my_swap, int bool);
void	ft_push_a(t_swap *my_swap, int bool);
void	ft_push_b(t_swap *my_swap, int bool);
void	check_eroor(t_swap *my_swap);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_inisialiser(t_swap *my_swap);
void	sort_tree(t_swap *my_swap);
void	sort_five(t_swap *my_swap);
void	push_sort(t_swap *my_swap);
void	ft_stock_tab(t_swap *my_swap);
void	ft_sort_tab(t_swap *my_swap);
int		ft_max_tab(t_swap *my_swap);
void	ft_s_tab(t_swap *my_swap);
int		ft_check_tab(t_swap *my_sawp, long n);
int		chek_max_tab(t_swap *my_swap);
void	ft_sort_algo(t_swap *my_swap);
void	ft_check_error(t_swap *my_swap, char **av);
void	check_isdigit(t_swap *my_swap, char **av);
void	push_min(t_swap *my_swap);
int		chek_min_tab(t_swap *my_swap);
char	*ft_strchr( char *s, int c);
char	*get_next_line(int fd);
char	*ft_readfile(char *str, int fd);
char	*ft__next(char *str);
char	*ft_ligne(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_checker(t_swap *my_swap, char *line);
int		check_sorted(t_swap *my_swap);
void	ft_read(t_swap *my_swap);
char	*ft_get_strjoin(char *s1, char *s2);
char	*ft_get_strchr(char *s, int c);
size_t	ft_get_strlen(char *str);
char	*ft_readfile(char *str, int fd);
char	*ft__next(char *str);
char	*ft_ligne(char *str);
void	ft_instock_tab(t_swap *my_swap);
void	ft_free_tab(t_swap *my_swap);

#endif
