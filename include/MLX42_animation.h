/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   MLX42_animation.h                                 :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/19 15:25:45 by sreerink      #+#    #+#                 */
/*   Updated: 2024/11/19 15:30:00 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX42_ANIMATION_H
# define MLX42_ANIMATION_H

# include "MLX42/MLX42.h"

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

t_sprite	*load_sprite_sheet(const char *file, int h, int w, mlx_t *mlx);

void		sprite_to_frame(mlx_image_t *img, t_sprite *s);

bool		add_frame(t_animation *a, t_sprite *s);

void		update_animation(t_animation *a, double dt);

t_animation	*init_animation(t_sprite *s, int n_frames, int row, int f_speed);

void		free_anim(t_animation *a);

#endif
