/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:51:55 by malexand          #+#    #+#             */
/*   Updated: 2016/05/07 14:13:24 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(char *src)
{
	char *p;
	int   count;
	int   size;

	size = ft_strlen(src);
	count    = 0;
	if (size == 0)
		return (NULL);
	p = (char *)(malloc(sizeof(char) * size));
	while (src[count] != '\0')
	{
		p[count] = src[count];
		count++;
	}
	p[count] = '\0';
	return (p);
}