/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder_managing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:11:05 by jvacaris          #+#    #+#             */
/*   Updated: 2022/04/26 19:35:48 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
* Nameless operation done multiple times in cylinder_lid and cylinder_wall.
*/
static float	do_the_f(t_coords vec_u, t_coords vec_w, t_coords vec_ori)
{
	return (dot_product(vec_u, vec_w) - dot_product(vec_ori, vec_u) * \
	dot_product(vec_ori, vec_w));
}

/**
* * This functions checks whether a ray collides with the LID of a cylinder.
* 
* @param ray Loc and dir (unit vector) of the ray coming out from the camera.
* @param cylinder The t_item struct of the cylinder being evaluated.
* @param coords Used to return the coordinates of the collision when successful.
* @param rev_ori Set to 1 if the normal vector of the lid matches the normal 
* vector of the cylinder. Otherwise, it returns -1.
* @retval 0 if the ray doesn't collide with the wall of the cylinder and 1 if 
* it does. The coordinates of the collision are returned via the coords 
* parameter.
*/
int	cylinder_lid(t_vectors ray, t_item cylinder, t_coords *coords, int *rev_ori)
{
	float	m;
	float	possible_ms[2];
	t_coords	pc;

	pc = v_v_sub(ray.loc, cylinder.loc);
	possible_ms[0] = (cylinder.height / 2.0 - dot_product(cylinder.orient, pc)) / dot_product(cylinder.orient, ray.dir);
	possible_ms[1] = (- cylinder.height / 2.0 - dot_product(cylinder.orient, pc)) / dot_product(cylinder.orient, ray.dir);
	if (possible_ms[0] >= 0.0 && (possible_ms[0] < possible_ms[1] || possible_ms[1] < 0.0))
	{
		m = possible_ms[0];
		if (rev_ori)
			*rev_ori = 1;
	}
	else if (possible_ms[1] >= 0.0 && (possible_ms[1] < possible_ms[0] || possible_ms[0] < 0.0))
	{
		m = possible_ms[1];
		if (rev_ori)
			*rev_ori = -1;
	}
	else
		return (0);
	if (do_the_f(v_v_sum(pc, v_f_mult(ray.dir, m)), v_v_sum(pc, v_f_mult(ray.dir, m)), cylinder.orient) >= powf(cylinder.diameter / 2.0, 2.0))
		return (0);
	*coords = v_v_sum(v_f_mult(ray.dir, m), ray.loc);
	return (1);
}

/**
* * This functions checks whether a ray collides with the WALL of a cylinder.
* * If the ray collides with a lid first and then comes out from a wall, this
* * function will consider it DOES NOT collide.
* 
* @param ray Loc and dir (unit vector) of the ray coming out from the camera.
* @param cylinder The t_item struct of the cylinder being evaluated.
* @param coords Used to return the coordinates of the collision when successful.
* @retval 0 if the ray doesn't collide with the wall of the cylinder and 1 if 
* it does. The coordinates of the collision are returned via the coords 
* parameter.
*/
int	cylinder_wall(t_vectors ray, t_item cylinder, t_coords *coords)
{
	float		m;
	float		possible_ms[2];
	t_coords	pc;

	pc = v_v_sub(ray.loc, cylinder.loc);
	if (!second_degree_equation(do_the_f(ray.dir, ray.dir, turn2unit(cylinder.orient)), 2.0 * do_the_f(pc, ray.dir, turn2unit(cylinder.orient)), \
	do_the_f(pc, pc, turn2unit(cylinder.orient)) - powf(cylinder.diameter / 2.0, 2.0), possible_ms))
		return (0);
	if (possible_ms[0] >= 0.0 && (possible_ms[0] < possible_ms[1] || possible_ms[1] < 0.0))
		m = possible_ms[0];
	else if (possible_ms[1] >= 0.0 && (possible_ms[1] < possible_ms[0] || possible_ms[0] < 0.0))
		m = possible_ms[1];
	else
		return (0);
	if (fabs(dot_product(cylinder.orient, v_v_sum(pc, v_f_mult(ray.dir, m)))) > cylinder.height / 2.0)
		return (0);
	if (coords)
		*coords = v_v_sum(ray.loc, v_f_mult(ray.dir, m));
	return (1);
}
