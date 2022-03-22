/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emadriga <emadriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:01:43 by jvacaris          #+#    #+#             */
/*   Updated: 2022/03/22 21:36:56 by emadriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H
# include "dtos.h"

int		**set_color_matrix(t_itemlist *items, t_coords **v_matrix);
int		check4collisions(t_coords vector, t_itemlist *items);

#endif
