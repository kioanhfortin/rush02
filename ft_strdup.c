/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:20:47 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:10:58 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_strdup.h"

char	*ft_strdup(char *str)
{
	char	*cpy;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * i)))
		return (0);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
