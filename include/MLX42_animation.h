/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   MLX42_animation.h                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/19 15:25:45 by sreerink      #+#    #+#                 */
/*   Updated: 2024/11/26 16:57:25 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX42_ANIMATION_H
# define MLX42_ANIMATION_H

# include "MLX42/MLX42.h"
# include <stdlib.h>

typedef struct s_sprite_sheet
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	uint32_t	slice_height;
	uint32_t	slice_width;
	uint32_t	cur_y;
	uint32_t	cur_x;
}	t_sprite;

typedef struct s_frame
{
	mlx_image_t		*img;
	struct s_frame	*next;
}	t_frame;

typedef struct s_animation
{
	struct s_frame	*frame;
	int				frame_speed;
	double			accum;
	int				current_frame;
	int				n_frames;
}	t_animation;

// Functions

void		px_to_px(mlx_image_t *d, mlx_image_t *s, uint32_t i_dst, uint32_t i_src);

void		clear_image(mlx_image_t *img);

void		put_img(mlx_image_t *dst, mlx_image_t *src, uint32_t y, uint32_t x);

t_sprite	*load_sprite_sheet(const char *file, int h, int w, mlx_t *mlx);

void		update_animation(t_animation *a, double dt);

t_animation	*init_animation(t_sprite *s, int n_frames, int row, int f_speed);

void		free_anim(t_animation *a);

#endif
