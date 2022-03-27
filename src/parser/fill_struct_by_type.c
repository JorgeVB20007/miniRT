/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_by_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:11:58 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/27 19:40:55 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_item	*line2alight(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = ALIGHT;
	item->brightness = ft_atof(line[1]);
	item->color = set_color(line[2]);
	return (item);
}

t_item	*line2camera(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = CAMERA;
	item->loc = set_coords(line[1]);
	item->orient = set_coords(line[2]);
	item->fov = ft_atof(line[3]);
	return (item);
}

t_item	*line2light(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = LIGHT;
	item->loc = set_coords(line[1]);
	item->brightness = ft_atof(line[2]);
	item->color.r = 255.0;
	item->color.g = 255.0;
	item->color.b = 255.0;
	return (item);
}

t_item	*line2sphere(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = SPHERE;
	item->loc = set_coords(line[1]);
	item->diameter = ft_atof(line[2]);
	item->color = set_color(line[3]);
	return (item);
}

t_item	*line2plane(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = PLANE;
	item->loc = set_coords(line[1]);
	item->orient = set_coords(line[2]);
	item->color = set_color(line[3]);
	return (item);
}

t_item	*line2cylinder(char **line)
{
	t_item	*item;

	item = malloc(sizeof(t_item));
	item->type = CYLINDER;
	item->loc = set_coords(line[1]);
	item->orient = set_coords(line[2]);
	ft_atof(line[3]);
	ft_atof(line[4]);
	item->color = set_color(line[5]);
	return (item);
}

