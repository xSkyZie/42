/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 23:24:43 by malexand          #+#    #+#             */
/*   Updated: 2016/05/07 14:13:05 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putstr(char *str, int output)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], output);
		i++;
	}
}