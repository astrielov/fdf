/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:31 by astrelov          #+#    #+#             */
/*   Updated: 2018/08/15 20:15:05 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

#include <stdio.h>

# define KEY_ESC_MAC		53
# define KEY_ESC_WINDOWS	65307
# define KEY_RIGHT_ARROW	65363
# define KEY_LEFT_ARROW		65361
# define KEY_UP_ARROW		65362
# define KEY_DOWN_ARROW		65364
# define KEY_1				49
# define KEY_2				50
# define KEY_3				51
# define KEY_Q				113
# define KEY_W				119
# define KEY_E				101
# define KEY_MINUS			45
# define KEY_PLUS			61
# define KEY_TAB			65289
# define KEY_BACKSPACE		65288

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	3
# define MOUSE_WHEEL_UP		4
# define MOUSE_WHEEL_DOWN	5

# define FALSE				0
# define TRUE				1

# define WIN_WIDTH			1280
# define WIN_HEIGHT			720

# define X_2D_SHIFT			WIN_WIDTH / 10
# define Y_2D_SHIFT			WIN_HEIGHT / 10

# define ZOOM_MULTIPLIER	1.2

# define HEIGHT_MULTIPLIER	1.2

# define ROTATE_X_ANGLE		30
# define ROTATE_Y_ANGLE		30
# define ROTATE_Z_ANGLE		30

# define FDF_COLOR_GRAY		0xa0a0a0

int 						fd_logfile; // DEBUG

typedef struct				s_rotate
{
	double					x_angle;
	double					y_angle;
	double					z_angle;
	double 					prev_x;
	double 					prev_y;
	double 					prev_z;
	int 					line;
	int 					lines;
	int 					column;
	int 					columns;
}							t_rotate;

typedef struct				s_image
{
	void					*img_ptr;
	char					*img_buff;
	int 					width;
	int 					height;
	int						bpp;
	int						size_line;
	int 					endian;
}							t_image;

typedef struct				s_dot_3d
{
	double 					x;
	double 					y;
	double 					z;
}							t_dot_3d;

typedef struct				s_map
{
	t_dot_3d				**dots_initial;
	t_dot_3d				**dots_curr;
	int 					lines;
	int						columns;
	double 					z_multiplier;
}							t_map;

typedef struct				s_view
{
	int						x_2d_shift;
	int 					y_2d_shift;
	float 					zoom_multiplier;
	double 					x_angle;
	double 					y_angle;
	double 					z_angle;
	int 					cam_dist;
	int 					info_color;
	int 					show_help;
}							t_view;

typedef struct				s_env
{
	void					*mlx_ptr;
	void					*win_ptr;
	t_image					s_img;
	t_map					s_map;
	t_view					s_view;
}							t_env;

void						set_initial_view_params(t_view *s_view, t_map *s_map);
void						parse_map(char *file, t_env *env);
void						render(t_env *env);

void						delete_image(void *mlx_ptr, t_image *s_img);
void						make_image(void *mlx_ptr, t_image *s_img);
void						fill_image_background(t_image *s_img, int color);
void						draw_line_in_img(t_dot_3d *d0, t_dot_3d *d1, t_env *env);

/*
** MAP CALCULATION
*/
void						dot_3d_to_2d(t_dot_3d *dot_2d, t_dot_3d *dot_3d, t_view *s_view);
int							calculate_2d_line_y(int x, t_dot_3d *d0, t_dot_3d *d1);
int							calculate_2d_line_x(int y, t_dot_3d *d0, t_dot_3d *d1);
void						rotate_dots_3_axis(t_map *s_map, t_view *s_view);
void						calculate_3d_map(t_map *s_map, t_view *s_view);

void 						rotate_xy_dots(t_rotate *r, t_dot_3d **dots);
void 						rotate_xz_dots(t_rotate *r, t_dot_3d **dots);
void 						rotate_yz_dots(t_rotate *r, t_dot_3d **dots);
void						rotate_xyz_dots(t_rotate *r, t_dot_3d **dots);


/*
** EVENTS
*/
int							handle_mouse_click(int button, int x, int y, t_env *env);
int 						handle_key_pressed(int key, t_env *env);
int							close_action();
void						zoom_action(int button, t_env *env);
void						change_land_height_action(int key, t_env *env);
void 						rotate_axis_action(int key, t_env *env);
void						move_map_action(int key, t_env *env);
void						help_toggle_action(t_env *env);
void 						reset_view_action(t_env *env);

/*
** SUNDRY
*/
void						del(void *content, size_t content_size);
int							strsplit_len(char **split);
void						print_info_to_win(void *mlx_ptr, void *win_ptr, t_map *s_map, t_view *s_view);
void						print_usage();
#endif
