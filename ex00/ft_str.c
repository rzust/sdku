/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatsumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 15:17:15 by nmatsumo          #+#    #+#             */
/*   Updated: 2018/08/05 15:39:26 by nmatsumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void		ft_writeerror(void)
{
	write(1, "ERROR\n", 6);
}

void		ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int			ft_strlen(char *ch)
{
	int n;

	n = 0;
	while (ch[n] != '\0')
		n++;
	return (n);
}
