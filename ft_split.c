/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:48:24 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:21:18 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_split.h"

int		ft_cont_c(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i] != c && charset[i])
		i++;
	return (charset[i] == c);
}

int		ft_size_split(char *str, char *charset)
{
	int i;
	int size;

	i = 0;
	size = 1;
	while (str[i])
	{
		if (ft_cont_c(charset, str[i]) && !ft_cont_c(charset, str[i + 1]))
			size++;
		i++;
	}
	if (ft_cont_c(charset, str[0]))
		size--;
	return (size);
}

int		ft_word(char *str, char *charset, int *ind)
{
	int i;
	int size;
	int pos;

	i = *ind;
	size = i;
	pos = i;
	while (((str[i] && (!ft_cont_c(charset, str[i]) &&
				!ft_cont_c(charset, str[i + 1]))) || (ft_cont_c(charset, str[i])
				&& !ft_cont_c(charset, str[i + 1]))))
	{
		pos++;
		i++;
		*ind = *ind + 1;
	}
	return (pos - size);
}

char	*print_word(int a, int ind, char *str)
{
	char	*cpy;
	int		i;
	int		k;

	k = 0;
	i = ind - a - 1;
	if (!(cpy = (char*)malloc(sizeof(char) * (a + 1))))
		return (0);
	while (i < ind)
	{
		cpy[k] = str[i];
		k++;
		i++;
	}
	cpy[k] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	int		ind;
	char	**tab;
	int		a;
	int		i;

	size = ft_size_split(str, charset);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 1))))
		return (0);
	ind = 0;
	i = 0;
	while (str[i])
	{
		a = ft_word(str, charset, &i);
		if (a)
		{
			tab[ind] = print_word(a, i + 1, str);
			ind++;
		}
		i++;
	}
	tab[ind] = 0;
	return (tab);
}
