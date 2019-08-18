/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoglobe <gdoglobe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:39:44 by gdoglobe          #+#    #+#             */
/*   Updated: 2019/08/18 22:32:20 by kifortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H
# define DIC_ENGLISH "../dict/numbers.dict"

int		ft_file_lines(char *file_path);
int		ft_check_input_args(int ac, char *av, int *inpt);

#endif
