/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:00:06 by alex              #+#    #+#             */
/*   Updated: 2016/05/07 13:03:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 	*ft_memalloc(size_t size)
{
	char	*data;
	size_t 	count;

	count = 0;
	data = (char *)malloc(size);
	if (data == NULL)
		return (NULL);
	while (count < size)
		data[count++] = '0';
	return ((void*)data);
}