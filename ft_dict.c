/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:15:46 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:40:12 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/ft_dict.h"
#include "../includes/t_number.h"

char	gc;
int		gfdr;
int		gi;
int		gj;

t_number	*ft_alloc_dict(char *fl_pth, t_number *n_d, int l)
{
	if ((gfdr = open(fl_pth, O_RDONLY)) < 0)
		return (NULL);
	gi = 0;
	gj = 0;
	while (read(gfdr, &gc, 1) && gj < l)
	{
		if (gc == '\n')
			gi++;
		else
		{
			n_d[gj].size = gi;
			n_d[gj].val_dico = (char*)malloc(sizeof(char) * n_d[gj].size);
			gi = 0;
			gj++;
		}
	}
	close(gfdr);
	return (n_d);
}

t_number	*ft_init_dict(char *fl_pth, t_number *n_d)
{
	if ((gfdr = open(fl_pth, O_RDONLY)) < 0)
		return (NULL);
	gj = 0;
	gi = 0;
	while (read(gfdr, &gc, 1))
	{
		if (gc != '\n')
		{
			n_d[gj].val_dico[gi] = gc;
			gi++;
		}
		else
		{
			n_d[gj].val_dico[gi] = '\0';
			n_d[gj].num = set_num(n_d[gj].val_dico);
			n_d[gj].alpha = set_alpha(n_d[gj].val_dico);
			gi = 0;
			gj++;
		}
	}
	close(gfdr);
	return (n_d);
}
