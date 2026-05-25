/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawurps <hawurps@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:19:05 by hawurps           #+#    #+#             */
/*   Updated: 2026/05/25 09:19:27 by hawurps          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	swap_pos(int i, int *pos)
{
	int	temp;

	temp = pos[i];
	pos[i] = pos[i + 1];
	pos[i + 1] = temp;
}

int	sort_args(int *pos, int n_arg, char **argv, int swapped)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	swapped = 0;
	while (i < n_arg - 1)
	{
		if (argv[pos[i]][j] > argv[pos[i + 1]][j])
		{
			swap_pos(i, pos);
			i++;
			j = 0;
			swapped = 1;
		}
		else if (argv[pos[i]][j] == argv[pos[i + 1]][j])
			j++;
		else
		{
			j = 0;
			i++;
		}
	}
	return (swapped);
}

void	write_args(int	*pos, int n_arg, char **argv)
{
	int		i;
	char	*str;
	char	c;

	i = 0;
	while (i < n_arg)
	{
		str = argv[pos[i]];
		while (*str)
		{
			c = *str;
			write(1, &c, 1);
			str++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pos[100];
	int	i;
	int	swapped;

	if (argc == 1)
		return (0);
	else
	{
		i = 1;
		while (i < argc)
		{
			pos[i - 1] = i;
			i++;
		}
		swapped = 1;
		while (swapped)
			swapped = sort_args(pos, argc - 1, argv, swapped);
		write_args(pos, argc - 1, argv);
	}
	return (0);
}
