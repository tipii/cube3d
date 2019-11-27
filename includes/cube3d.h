/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpalhol <tpalhol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:37:21 by tpalhol           #+#    #+#             */
/*   Updated: 2019/11/27 14:47:50 by tpalhol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "env.h"
# include "keys.h"


# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>


t_env		*init_env();

void		draw_column(t_env *env);
void		render(t_env *env);
int			generate_color(int r, int g, int b);
double		deg_to_radian(double deg);
int			hook_keydown(int key, t_env *env);

#endif