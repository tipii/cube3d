/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:26:53 by tpalhol           #+#    #+#             */
/*   Updated: 2020/01/21 13:37:43 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define FOV 60
# define H_WALL 64
# define H_PLAYER 64

typedef	struct s_checks
{
	int				found_res;
	int				found_player;
	int				found_map;
	int				found_textN;
	int				found_textS;
	int				found_textE;
	int				found_textW;
	int				found_sprite;
	int				found_ceiling;
	int				found_floor;
	int				fd;
	char			**line;
	char			**args;
	int				i;
	int				j;
	int				k;
}				t_checks;

typedef struct s_text
{
	void		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	char		*data;
}				t_text;

typedef struct s_sprite
{
	void		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
	char		*data;
	int			posx;
	int			posy;
}				t_sprite;

typedef	struct	s_env
{
	///PLAYER INFOS
	double			posX;
	double			posY;
	double			t_speed;
	double			r_speed;
	/* direction of player */
	double			dirX;
	double			dirY;
	/* stock old dirX and dirY */
	double			oldDirX;
	double			oldDirY;
	/* resolution */
	int		resX;
	int		resY;
	/* height of wall / player */
	double		wallH;
	double		playerH;
	/* field of view */
	double		fov;
	/* map */
	char			**map;
	int				mapWidth;
	int				mapHeight;
	/* current pos on map */
	int			mapX;
	int			mapY;
	/* camera plane */
	double		planeX;
	double		planeY;
	double		oldPlaneX;
	double		oldPlaneY;
	/* definig wich ray (left -1 to right 1) and dir */
	int			x;
	int			y;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	/* ray dist to next case on map */
	double		sideDistX;
	double		sideDistY;
	/* length of ray from one x or y-side to next x or y-side */
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	/* step in x and y (-1 or +1) according to cam vector*/
	int			stepX;
	int			stepY;
	/* when a wall is hit */
	int			hit;
	/* side of wall */
	int			side;
	/* textures variables */
	double		wallX;
	int			texX;
	double		step;
	double		texPos;
	int			texY;
	/* wall and floor variables */
	double		floorx_wall;
	double		floory_wall;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		current_floorx;
	double		current_floory;
	int			floor_textx;
	int			floor_texty;
	int			ceil_textx;
	int			ceil_texty;
	/* sprites */
	int			countsprite;
	int			isprite;
	int			jsprite;
	t_sprite	**sprites;
	double		*zbuffer;
	int			*s_order;
	double		*sprite_distance;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;
	int			spritewidth;
	int			stripe;
	int			d;
	int			color;
	/* mlx prop */
	int			bpp;
	int			size_line;
	int			endian;
	void		*mlx;
	void		*window;
	void		*img;
	char		*img_data;
	/*DRAW*/
	float		lumvalue;
	int			lum;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	t_text		**text;
	t_text		*textF;
	t_text		*textC;
	int			has_text_floor;
	int			has_text_ceiling;
	int			color_floor;
	int			color_ceiling;
	t_checks	*c;
	/* is_init */
	int			malloc_check;
	int			malloc_map;
	int			malloc_sprites;
	int			malloc_textures;
	int			malloc_textures_floor;
	int			malloc_textures_ceiling;
	/* move */
	int			rotate_left;
	int			rotate_right;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
}				t_env;

void		init_map(int width, int height, t_env *env);
void		init_sprite(int i, t_env *env);
void		show_map(t_env *env);
void		get_lum_value(t_env *env);
void		sprite_casting(t_env *env);
void		set_player_value(char c, t_env *env);
void		load_texture(char *filepath, t_text *text, t_env *env);
void		load_sprite(char *filepath, t_sprite *text, t_env *env);
void		load_floor_or_ceil(char* arg1, char*arg2, t_env *env);
#endif