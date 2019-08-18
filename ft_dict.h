/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:54:43 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:32:06 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICT_H
# define FT_DICT_H

typedef struct s_number	t_number;
number		*ft_alloc_dict(char *fl_pth, number *n_d, int l);
number		*ft_init_dict(char *fl_pth, number *n_d);

#endif
