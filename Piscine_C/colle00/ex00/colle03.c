/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 19:04:30 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 01:22:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		ft_atoi(char *src);

void	ft_extremum(int x)
{
	int i;

	i = 0;
	ft_putchar('A');
	while (i++ < x - 2)
		ft_putchar('B');
	if (x != 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	colle(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		ft_extremum(x);
		i = 0;
		while (i < y - 2)
		{
			ft_putchar('B');
			if (x != 1)
			{
				j = 0;
				while (j++ < x - 2)
					ft_putchar(' ');
				ft_putchar('B');
			}
			ft_putchar('\n');
			i++;
		}
		i = 0;
		if (y != 1)
			ft_extremum(x);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	colle(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return 0;
}