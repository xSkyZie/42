/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/11/25 14:03:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int		atoi_3d(char ***tabstr)
{
	(void)tabstr;
	return (1);
}

static	char	*parse_str(char *str)
{
	char	***str_parse;

	str_parse = parse_array_3d(str, '\n', ' ');
	putarray_3d(str_parse);
	atoi_3d(str_parse);
	return (str);
}

char			*parse_file(const char *file_name)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*str;

	fd = 0;
	ret = 0;
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(1, 1, "");
	while ((ret = get_next_line(fd, &tmp)) == 1)
		str = ft_strjoin_free_endl(str, tmp);
	if (ret == -1)
		error(1, 1, "");
	ft_strdel(&tmp);
	if (close(fd) < 0)
		error(1, 1, "");
	parse_str(str);
	return (NULL);
}