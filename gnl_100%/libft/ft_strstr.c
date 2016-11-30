/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:14:59 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/23 20:16:01 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(char *place, char *search)
{
	size_t n;

	n = ft_strlen(search);
	if (*search == '\0')
		return (place);
	while (*place)
	{
		if (!ft_memcmp(place++, search, n))
			return (place - 1);
	}
	return (0);
}