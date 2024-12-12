/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   update_animation.c                                :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/26 17:03:17 by sreerink      #+#    #+#                 */
/*   Updated: 2024/12/12 22:51:38 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MLX42_animation.h"

mlx_image_t	*get_frame_num(t_animation *a, int cur_frame)
{
	t_frame	*temp;

	temp = a->frame;
	while (cur_frame > 0)
	{
		temp = temp->next;
		cur_frame--;
	}
	return (temp->img);
}

void	update_animation(t_animation *a, double dt)
{
	a->accum += dt * 1000;
	if (a->accum > a->frame_speed)
	{
		a->accum -= a->frame_speed;
		a->current_frame++;
		a->current_frame %= a->n_frames;
	}
}
