/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_change_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 10:33:03 by null              #+#    #+#             */
/*   Updated: 2018/08/15 14:02:00 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 	reset_view_action(t_env *env)
{
	set_initial_view(env);
	render(env);
}

void	help_toggle_action(t_env *env)
{
	env->s_view.show_help = !env->s_view.show_help;
	render(env);
}

void	zoom_action(int button, t_env *env)
{
	if (button == MOUSE_WHEEL_UP)
		env->s_view.zoom_multiplier *= ZOOM_MULTIPLIER;
	if (button == MOUSE_WHEEL_DOWN)
		env->s_view.zoom_multiplier /= ZOOM_MULTIPLIER;
	render(env);
}

void	change_land_height_action(int key, t_env *env)
{
	env->s_map.z_multiplier *= (key == KEY_PLUS) ? 2 : 0.5;
	render(env);
}

void	move_map_action(int key, t_env *env)
{
	if (key == KEY_LEFT_ARROW)
		env->s_view.x_2d_shift -= X_2D_SHIFT;
	if (key == KEY_RIGHT_ARROW)
		env->s_view.x_2d_shift += X_2D_SHIFT;
	if (key == KEY_UP_ARROW)
		env->s_view.y_2d_shift -= Y_2D_SHIFT;
	if (key == KEY_DOWN_ARROW)
		env->s_view.y_2d_shift += Y_2D_SHIFT;
	render(env);
}

void 	rotate_axis_action(int key, t_env *env)
{
	if (key == KEY_1)
		env->s_view.x_angle -= ROTATE_X_ANGLE;
	if (key == KEY_Q)
		env->s_view.x_angle += ROTATE_X_ANGLE;
	if (key == KEY_2)
		env->s_view.y_angle -= ROTATE_Y_ANGLE;
	if (key == KEY_W)
		env->s_view.y_angle += ROTATE_Y_ANGLE;
	if (key == KEY_3)
		env->s_view.z_angle -= ROTATE_Z_ANGLE;
	if (key == KEY_E)
		env->s_view.z_angle += ROTATE_Z_ANGLE;
	render(env);
}
