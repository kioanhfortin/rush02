/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 10:34:17 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:26:12 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/number.h"
#include "../includes/ft_atoi.h"
#include "../includes/ft_split.h"
#include "../includes/ft_strdup.h"
#include "../includes/ft_file.h"
#include "../includes/ft_dict.h"

void	ft_print_dict(int num, number *n_d)
{
	int	k;

	k = 0;
	while (n_d[k].val_dico)
	{
		if (n_d[k].num == num && num != 0)
			//printf("%s",n_d[k].alpha);
		else if (n_d[k].num == num && num == 0)
			//printf("%s","");
		k++;
	}
}

int		ft_srtlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

number		*dico_numer;

void 	numToWords(int n, char * s)
{
	if (n > 2)
	{
		ft_print_dict((n / 10) * 10, dico_numer);
		printf("%s"," ");
		ft_print_dict(n % 10, dico_numer);
	}
	else
		ft_print_dict(n,dico_numer);
	if (n)
		printf("%s",s);
}

void	convertToWords(long n)
{
	numToWords((n / 1000000000), " bilion ");
    n = n % 1000000000;
	numToWords((n / 100000000) % 10, " hundred ");
	if((n/100000000) > 1 && (n %100000000) < 10000000)
	//	printf("%s"," million ");
	numToWords((n / 1000000) % 100, " millions");
	numToWords(((n / 100000) % 10), " hundred ");
	if((n/100000) > 1  && (n %100000) < 10000)
	//	printf("%s"," thousand ");
	numToWords(((n / 1000) % 100), " thousand ");
	numToWords(((n / 100) % 10), " hundred ");
	if (n > 100 && n % 100)
	//	printf(" and ");
	numToWords((n % 100), "");
}


int		main(int argc, char *argv[])
{
	int a;
	int i;

	a = 0;
	i = 0;
	if (ft_check_input_args(argc, argv[1], &a) < 0 ||
			(i = ft_file_lines(DIC_ENGLISH)) < 0)
		return (0);
	i = ft_file_lines(DIC_ENGLISH);
	dico_numer = (number*)malloc(sizeof(number) * i);
	if (!ft_alloc_dict(DIC_ENGLISH, dico_numer, i) || !dico_numer)
		return (0);
	if (!ft_init_dict(DIC_ENGLISH, dico_numer))
		return (0);
	if (a == 0)
	{
		//printf( "zero" );
		return 0;
	}
	convertToWords(a);
	return (0);
}
