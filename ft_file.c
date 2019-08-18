/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:55:41 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/17 22:14:08 by gdoglobe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../includes/ft_atoi.h"
#include "../includes/ft_file.h"

int		ft_file_lines(char *file_path)
{
	int		fdr;
	char	c;
	int		i;

	if ((fdr = open(file_path, O_RDONLY)) < 0)
		return (-1);
	i = 0;
	while (read(fdr, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close(fdr);
	return (i);
}

int		ft_check_input_args(int ac, char *av, int *inpt)
{
	if (ac != 2 || (*inpt = ft_atoi(av)) < 0)
	{
		write(1, "error", 5);
		return (-1);
	}
	return ((*inpt));
}
