/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:39:43 by tpalhol           #+#    #+#             */
/*   Updated: 2020/01/09 12:45:32 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void show_map(t_env *env)
{
	int x = 0;
	int y = 0;
	printf("\x1b[33mMap...\x1b[39m\n\n");
	while (env->map[y])
	{
		while (env->map[y][x])
		{
			printf("%c ", env->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
		x = 0;
	}
	printf("\n");
}


// int	main()
// {
// 	t_player	*player;
// 	int			**map;

// 	if(!(player = init_player()))
// 		return (0);
// 	printf("x : %f, y : %f\n", player->pos_x, player->pos_y);

// 	printf("\n---------\n\n");
// 	if(!(map = init_map(5, 5)))
// 		return (0);
// 	show_map(map, 5,5);
// 	return (0);
// }
void loop(t_env *env)
{
	mlx_loop(env->mlx);
}

// MAIN TEST //
int main()
{

	t_env		*env;
	// init_all(player, env);
	if (!(env = init_env()))
		return(0);
	parse("./maps/map_1.cub", env);
	printf("\n\x1b[33mParsing...\x1b[39m\n\n");

	printf("MAP : Width : %d, Height : %d \n", env->mapWidth, env->mapHeight);
	printf("PLAYER : Pos x %f, Pos y %f\n", env->posX, env->posY);
	env->mlx = mlx_init();
	printf("\n\x1b[33mInitializing...\x1b[39m\n\n");
	printf("RES : x %d, y %d\n", env->resX, env->resY);
	// printf("%f\n", (((2 * 719) / (double)env->resX) -1 ));

	env->window = mlx_new_window(env->mlx, env->resX, env->resY, "AWESOME RAYCASTING SHIT V0.0000001beta");
	env->img = mlx_new_image (env->mlx, env->resX, env->resY);
	env->img_data = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);

	printf("MLX INFOS : bpp : %d, size_line : %d, endian : %d \n\n", env->bpp, env->size_line, env->endian);
	show_map(env);

	render(env);
	// exit(0);
	mlx_hook(env->window, 2, 1L << 0, hook_keydown, env);
	loop(env);

	return (0);
}

