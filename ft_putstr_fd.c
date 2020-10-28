/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 22:20:04 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/23 06:24:30 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_c(char *str)
{
	int count;

	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free(str);
	return (count);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int		print_negative_int(int *infos, int str)
{
	char *to_print;
	char *tmp;

	to_print = ft_itoa(str);
	tmp = min_width(to_print + 1, infos[2], 1);
	free(to_print);
	to_print = ft_strjoin("-", tmp);
	if (infos[1] && infos[2] < 0 && infos[0] == 1)
	{
		tmp = min_width(to_print + 1, infos[1] - 1, 1);
		free(to_print);
		to_print = ft_strjoin("-", tmp);
	}
	if (infos[1] && infos[1] > (int)ft_strlen(to_print))
	{
		if (infos[0] == 1 || !infos[0])
			tmp = min_width(to_print, infos[1], 0);
		else
			tmp = min_width(to_print, infos[1], 2);
		free(to_print);
		to_print = tmp;
	}
	return (ft_putstr_c(to_print));
}

void	print_int_precision(char **to_print, int *infos)
{
	char *tmp;

	if (infos[2] >= 0)
	{
		if (infos[2] > (int)ft_strlen(*to_print))
		{
			tmp = min_width(*to_print, infos[2], 1);
			free(*to_print);
			*to_print = tmp;
		}
		if (infos[1] > (int)ft_strlen(*to_print))
		{
			if (infos[1] >= 0 && (infos[0] == 1 || !infos[0]))
				tmp = min_width(*to_print, infos[1], 0);
			else
				tmp = min_width(*to_print, infos[1], 2);
			free(*to_print);
			*to_print = tmp;
		}
	}
}
