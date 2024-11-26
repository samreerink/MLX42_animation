/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   free_animation.c                                  :+:    :+:             */
/*                                                    +:+                     */
/*   By: sreerink <sreerink@student.codam.nl>        +#+                      */
/*                                                  +#+                       */
/*   Created: 2024/11/26 16:46:41 by sreerink      #+#    #+#                 */
/*   Updated: 2024/11/26 16:46:56 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MLX42_animation.h"

void	free_anim(t_animation *a)
{
	t_frame	*current;
	t_frame	*temp;

	if (!a)
		return ;
	current = a->frame;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(a);
}
