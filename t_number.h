/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_number.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:41:38 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:38:24 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_NUMBER_H
# define T_NUMBER_H

typedef struct	s_number
{
	int		num;
	char	*alpha;
	int		size;
	char	*val_dico;
}				t_number;

int				set_num(char *str);
char			*set_alpha(char *str);

#endif
