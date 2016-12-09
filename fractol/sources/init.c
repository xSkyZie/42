/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:20:05 by malexand          #+#    #+#             */
/*   Updated: 2016/12/09 12:15:51 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_img			*init_img(t_env *e)
{
	t_img	*img;

	img = NULL;
	if ((img = (t_img *)malloc(sizeof(t_img))) == NULL)
		error(1, 0, "Malloc struct img");
	img->img = mlx_new_image(e->mlx, e->width, e->heigth);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->size_l),
		&(img->endian));
	return (img);
}

t_env			*init_env(t_env *e, int w, int h)
{
	if ((e = (t_env *)malloc(sizeof(t_env))) == NULL)
		error(1, 0, "Malloc struct e");
	e->mlx = mlx_init();
	if (w < 250 || h < 250 || w > 2550 ||
		h > 1080)
	{
		w = 1000;
		h = 1000;
	}
	e->width = 1000;
	e->heigth = 1000;
	e->win = mlx_new_window(e->mlx, e->width, e->heigth, "fractol");
	e->img = init_img(e);
	e->dx = 0;
	e->dy = 0;
	e->reload = 0;
	e->color = 0xFFFFFF;
	return (e);
}
