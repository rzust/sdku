/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatsumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:32:16 by nmatsumo          #+#    #+#             */
/*   Updated: 2018/08/05 23:20:41 by nmatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_sudoku_etc.h"
#include "ft_str.h"

char	**g_sudoku;
int		g_check_result;

void		ft_sudoku_display(void)
{
	int		x;
	int		y;
	char	ch;

	x = 0;
	y = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ch = (char)g_sudoku[x][y] + '0';
			ft_putchar(ch);
			if (y < 8)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			y++;
		}
		x++;
	}
	return ;
}

void		ft_checkdisplay(int **sudoku)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (g_sudoku[x][y] == 0)
			{
				g_sudoku[x][y] = sudoku[x][y];
			}
			else if (g_sudoku[x][y] != sudoku[x][y])
			{
				g_check_result = -1;
				return ;
			}
			y++;
		}
		x++;
	}
	g_check_result = 1;
}

void		ft_sudokuget_ans(int x, int y, int num, int **su)
{
	int		next;
	int		check_result;

	if (g_check_result == -1)
		return ;
	while (su[x][y] != 0)
	{
		x++;
		if (x >= 9)
		{
			x = 0;
			y++;
			if (y == 9)
				ft_checkdisplay(su);
		}
	}
	if (ft_exist_check(x, y, num, su) == 1)
		return ;
	su[x][y] = num;
	next = 1;
	while (next <= 9)
		ft_sudokuget_ans(x, y, next++, su);
	su[x][y] = 0;
}

void		ft_sudokuget_reverse_ans(int x, int y, int num, int **su)
{
	int		next;
	int		check_result;

	if (g_check_result == -1)
		return ;
	while (su[x][y] != 0)
	{
		x--;
		if (x < 0)
		{
			x = 8;
			y--;
			if (y == -1)
				ft_checkdisplay(su);
		}
	}
	if (ft_exist_check(x, y, num, su) == 1)
		return ;
	su[x][y] = num;
	next = 1;
	while (next <= 9)
		ft_sudokuget_reverse_ans(x, y, next++, su);
	su[x][y] = 0;
}

int			**ft_get_board(int argc, char **argv)
{
	int		**sudoku;
	int		rlen;
	int		count;

	sudoku = malloc(sizeof(int*) * 9);
	count = 1;
	while (count < 10)
	{
		if (argc != 10 || ft_strlen(argv[count]) != 9)
		{
			ft_writeerror();
			return (NULL);
		}
		sudoku[count - 1] = malloc(sizeof(int) * 9);
		rlen = 0;
		while (rlen < 9)
		{
			sudoku[count - 1][rlen] = ft_toint(argv[count][rlen]);
			rlen++;
		}
		count++;
	}
	return (sudoku);
}

int		ft_check_numcount(int **sudoku)
{
	int		count;
	int		x;
	int		y;

	x = 0;
	count = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			if (sudoku[x][y] != 0)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

void		ft_initialize_global(void)
{
	int		x;
	int		y;

	g_sudoku = malloc(sizeof(int*) * 9);
	g_check_result = 0;
	x = 0;
	while (x < 9)
	{
		g_sudoku[x] = malloc(sizeof(int) * 9);
		y = 0;
		while (y < 9)
		{
			g_sudoku[x][y] = 0;
			y++;
		}
		x++;
	}
}

void		ft_sudoku(int argc, char **argv)
{
	int		count;
	int		**su;

	ft_initialize_global();
	su = ft_get_board(argc, argv);
	if (su == NULL)
		return ;
	if (ft_check_numcount(su) <= 16)
	{
		ft_writeerror();
		return ;
	}
	count = 1;
	while (count < 10)
		ft_sudokuget_ans(0, 0, count++, su);
	su = ft_get_board(argc, argv);
	count = 1;
	while (count < 10)
		ft_sudokuget_reverse_ans(8, 8, count++, su);
	if (g_check_result == 1)
		ft_sudoku_display();
	else
		ft_writeerror();
}

int			main(int argc, char **argv)
{
	ft_sudoku(argc, argv);
	return (0);
}
