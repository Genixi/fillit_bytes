/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:07:18 by bpole             #+#    #+#             */
/*   Updated: 2019/10/15 18:51:58 by equiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_put_error(const char *s)
{
	if (s)
		ft_putendl(s);
	return (-1);
}

int			main(int ac, char **av)
{
	t_tet	tet[FIG_MAX + 1];
	short	arr[16];
	int		count;
	int		size;
	int		fd;

	count = 0;
	size = 0;
	if (ac != 2)
		return (ft_put_error("usage : ./fillit input_file"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (ft_put_error("error"));
	ft_bzero(tet, sizeof(t_tet) * FIG_MAX + 1);
	if ((count = read_file(tet, fd, count)) == -1)
		return (ft_put_error("error"));
	while (size * size < count * 4 || !find_solution(tet, arr, size))
	{
		ft_bzero(arr, sizeof(arr));
		size++;
	}
	print_result(tet, size);
	return (0);
}
