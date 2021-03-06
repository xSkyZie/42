/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 13:56:26 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 23:29:23 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_colle.h"

t_dimension	count_dim(char *buf, t_dimension dimension)
{
	while (buf[dimension.x] != '\0')
	{
		if (buf[dimension.x] == '\n')
			dimension.y++;
		dimension.x++;
	}
	dimension.x = (dimension.x / dimension.y) - 1;
	return (dimension);
}

t_verif		ft_put(int x, int y, char *str, t_verif *verif)
{
	if (verif->pipe == 0)
		verif->pipe = 1;
	else if (verif->pipe == 1 && str[8] != '0')
		ft_putstr(" || ");
	ft_putstr(str);
	ft_putstr(" [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putstr("]");
	verif->find = 1;
	return (*verif);
}

int			ft_str_compare(char *str, int x, int y)
{
	char		tab[y * x + y + 1];
	t_verif		verif;

	verif.pipe = 0;
	verif.find = 0;
	colle00(tab, x, y);
	if (ft_strcmp(tab, str))
		verif = ft_put(x, y, "[colle-00]", &verif);
	colle01(tab, x, y);
	if (ft_strcmp(tab, str))
		verif = ft_put(x, y, "[colle-01]", &verif);
	colle02(tab, x, y);
	if (ft_strcmp(tab, str))
		verif = ft_put(x, y, "[colle-02]", &verif);
	colle03(tab, x, y);
	if (ft_strcmp(tab, str))
		verif = ft_put(x, y, "[colle-03]", &verif);
	colle04(tab, x, y);
	if (ft_strcmp(tab, str))
		verif = ft_put(x, y, "[colle-04]", &verif);
	if (verif.find == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
	return (0);
}

int			main(int argc, char **argv)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*save;
	int			i;
	t_dimension dim;

	if (argc == 1 && argv[1] == argv[1])
	{
		i = 0;
		save = (char*)malloc(sizeof(save));
		while (read(0, buffer, BUFFER_SIZE))
		{
			save[i] = buffer[0];
			i++;
		}
		if (save[0 != '\0'])
		{
			dim = count_dim(save, dim);
			ft_str_compare(save, dim.x, dim.y);
		}
		else
			ft_putstr("aucune\n");
	}
	else
		ft_putstr("Too many arguments.\n");
	return (0);
}
