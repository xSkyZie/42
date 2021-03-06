/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 19:02:38 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 20:50:48 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_extremum_up00(int x, char *tab, int k)
{
	int i;

	i = 0;
	tab[k] = 'o';
	k++;
	while (i++ < x - 2)
	{
		tab[k] = '-';
		k++;
	}
	if (x != 1)
	{
		tab[k] = 'o';
		k++;
	}
	tab[k] = '\n';
	k++;
	return (k);
}

int		ft_extremum_down00(int x, char *tab, int k)
{
	int i;

	i = 0;
	tab[k] = 'o';
	k++;
	while (i++ < x - 2)
	{
		tab[k] = '-';
		k++;
	}
	if (x != 1)
	{
		tab[k] = 'o';
		k++;
	}
	tab[k] = '\n';
	k++;
	return (k);
}

int		ft_center00(int x, int y, char *tab, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		tab[k] = '|';
		k++;
		if (x != 1)
		{
			j = 0;
			while (j++ < x - 2)
			{
				tab[k] = ' ';
				k++;
			}
			tab[k] = '|';
			k++;
		}
		tab[k] = '\n';
		k++;
		i++;
	}
	return (k);
}

void	colle00(char *tab, int x, int y)
{
	int i;
	int k;

	k = 0;
	tab[0] = '\0';
	if (x > 0 && y > 0)
	{
		k = ft_extremum_up00(x, tab, k);
		i = 0;
		k = ft_center00(x, y, tab, k);
		i = 0;
		if (y != 1)
			k = ft_extremum_down00(x, tab, k);
		tab[k] = '\0';
	}
}
