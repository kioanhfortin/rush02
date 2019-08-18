/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:36:17 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:11:31 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_strdup.h"
#include "../includes/number.h"

int		set_num(char *str)
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res);
}

char	*set_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i - 1] != ' ')
		i++;
	return (ft_strdup(&str[i]));
}
