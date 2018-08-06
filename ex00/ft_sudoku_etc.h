/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku_etc.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatsumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:20:08 by nmatsumo          #+#    #+#             */
/*   Updated: 2018/08/05 15:44:48 by nmatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_ETC_H
# define FT_SUDOKU_ETC_H
# include <stdlib.h>
# include <unistd.h>

int		ft_toint(char ch);
int		ft_rcexist(int x, int y, int num, int **su);
int		ft_cexist(int x, int y, int num, int **su);
int		ft_rexist(int x, int y, int num, int **su);
int		ft_exist_check(int x, int y, int num, int **su);
#endif
