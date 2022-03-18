/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvacaris <jvacaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:41:18 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/18 16:59:34 by jvacaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "dtos.h"

/**
 * * Add new node into list at begining
 * @param list		list
 * @param new_node	new node to link
*/
void		lst_rt_add_front(t_itemlist **alst, t_itemlist *new_node);

/**
 * * Free list
 * @param list	list
*/
void	lst_rt_free(t_itemlist **list);

/**
 * * Returns malloced node
*/
t_itemlist	*lst_rt_new(t_item *content);

/**
 * * Print list
 * @param list
*/
void	lst_rt_print(t_itemlist *list);

/**
 * * Returns an item_list of t_itemlist that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
t_item		get_item_by_type(t_itemlist **item_list, int type);

/**
 * * Returns an item_list of t_itemlist that has the type given.
 * @param item_list	list of items
 * @param type		type of item_list to get
*/
void	get_items_by_type(t_itemlist **filtered_list, t_itemlist *list, int type);

/**
 * * Turns degrees into radians.
*/
float		deg2rad(float deg);

/**
 * * Turns radians into degrees.
*/
float		rad2deg(float rad);

/**
 * * Returns vector's module
 * @param vector
*/
float		getmodule(t_coords vector);

t_colors	set_color(const char *rgb);

t_coords	set_coords(const char *coords);

t_coords	v_v_cross_product(t_coords a, t_coords b);

t_coords	v_v_sub(t_coords a, t_coords b);

t_coords	v_v_sum(t_coords a, t_coords b);

t_coords	v_i_mult(t_coords v, int i);

#endif
