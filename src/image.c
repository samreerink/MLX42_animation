/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   image.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/26 16:48:42 by sreerink      #+#    #+#                 */
/*   Updated: 2024/11/26 17:00:58 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MLX42_animation.h"

void	px_to_px(mlx_image_t *d, mlx_image_t *s, uint32_t i_dst, uint32_t i_src)
{
	d->pixels[i_dst] = s->pixels[i_src];
	d->pixels[i_dst + 1] = s->pixels[i_src + 1];
	d->pixels[i_dst + 2] = s->pixels[i_src + 2];
	d->pixels[i_dst + 3] = s->pixels[i_src + 3];
}

static void	*anim_memset(void *b, int c, size_t len)
{
	unsigned char	*str_caster;
	size_t			i;

	str_caster = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str_caster[i] = c;
		i++;
	}
	return (str_caster);
}

void	clear_image(mlx_image_t *img)
{
	uint32_t	h;
	uint32_t	w;

	h = img->height;
	w = img->width;
	anim_memset(img->pixels, 0xFF000000, w * h * sizeof(uint32_t));
}

void	put_img(mlx_image_t *dst, mlx_image_t *src, uint32_t y, uint32_t x)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	old_x;
	uint32_t	index_src;
	uint32_t	index_dst;

	i = 0;
	old_x = x;
	while (i < src->height)
	{
		j = 0;
		x = old_x;
		while (j < src->width)
		{
			index_dst = (y * dst->width + x) * 4;
			index_src = (i * src->width + j) * 4;
			px_to_px(dst, src, index_dst, index_src);
			j++;
			x++;
		}
		i++;
		y++;
	}
}
