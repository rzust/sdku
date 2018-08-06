/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_etc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatsumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:44:22 by nmatsumo          #+#    #+#             */
/*   Updated: 2018/08/05 23:10:23 by nmatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			ft_rexist(int x, int y, int num, int **su)
{
	y = 0;
	while (y < 9)
		if (su[x][y++] == num)
			return (1);
	return (0);
}

int			ft_cexist(int x, int y, int num, int **su)
{
	x = 0;
	while (x < 9)
		if (su[x++][y] == num)
			return (1);
	return (0);
}

int			ft_rcexist(int x, int y, int num, int **su)
{
	int		ix;
	int		iy;

	x = x - (x % 3);
	y = y - (y % 3);
	ix = 0;
	while (ix < 3)
	{
		iy = 0;
		while (iy < 3)
		{
			if (su[x + ix][y + iy] == num)
				return (1);
			iy++;
		}
		ix++;
	}
	return (0);
}

int			ft_toint(char ch)
{
	int		n;

	n = (int)ch - '0';
	if (n == -2)
		n = 0;
	return (n);
}

int			ft_exist_check(int x, int y, int num, int **su)
{
	if (ft_rexist(x, y, num, su) == 1)
		return (1);
	if (ft_cexist(x, y, num, su) == 1)
		return (1);
	if (ft_rcexist(x, y, num, su) == 1)
		return (1);
	return (0);
}
