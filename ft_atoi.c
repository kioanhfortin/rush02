/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:27:02 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:10:33 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_atoi.h"

int		ft_atoi(char *str)
{
	int result;
	int puiss;

	while (*str && (*str == ' ' || *str == '\t' || *str == '\v' ||
				*str == '\f' || *str == '\n' || *str == '\r'))
		str++;
	result = 0;
	puiss = 1;
	while ((*str && ('-' == (*str))) || ((*str) == '+'))
	{
		if (*str == '-')
			puiss = puiss * -1;
		str++;
	}
	while (*str)
	{
		if ((*str) < '0' || (*str) > '9')
			return (-1);
		result = (result * 10) + ((*str) - '0');
		str++;
	}
	return (result * puiss);
}
