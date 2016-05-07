/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:04:54 by alex              #+#    #+#             */
/*   Updated: 2016/05/07 14:07:16 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
	char	*str;
	size_t	count;

	count = 0;
	if (s && f)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str == NULL)
			return(NULL);
		while(s[count])
		{
			str[count] = f(count, s[count]);
			count++;
		}
		str[count] = '\0';
		return(str);
	}
	else
		return (NULL);
}