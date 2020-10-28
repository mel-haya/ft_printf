/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:58:26 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/23 06:23:25 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		print_str(int *infos, char *str)
{
	char	*to_print;
	char	*str_null;
	char	*tmp;

	str_null = "(null)";
	if (!str)
		to_print = ft_strdup(str_null);
	else
		to_print = ft_strdup(str);
	if (infos[2] >= 0)
		to_print[infos[2]] = 0;
	if (infos[1] > 0 && infos[1] > (int)ft_strlen(to_print))
	{
		tmp = min_width(to_print, infos[1], infos[0]);
		free(to_print);
		to_print = tmp;
	}
	return (ft_putstr_c(to_print));
}

int		print_int(int *infos, int str)
{
	char *to_print;
	char *tmp;

	if (str < 0)
		return (print_negative_int(infos, str));
	to_print = ft_itoa(str);
	if (!str && !infos[2])
		to_print[0] = 0;
	print_int_precision(&to_print, infos);
	if (infos[1] && infos[2] < 0 && infos[1] > (int)ft_strlen(to_print))
	{
		tmp = min_width(to_print, infos[1], infos[0]);
		free(to_print);
		to_print = tmp;
	}
	return (ft_putstr_c(to_print));
}

int		print_pointer(int *infos, void *str)
{
	char *to_print;
	char *tmp;

	tmp = dec_to_hex((unsigned long long)str, 0);
	to_print = ft_strjoin("0x", tmp);
	if (!infos[2] && !str)
		to_print[2] = 0;
	free(tmp);
	if (infos[1] > 0 && infos[1] > (int)ft_strlen(to_print))
	{
		tmp = min_width(to_print, infos[1], infos[0]);
		free(to_print);
		to_print = tmp;
	}
	return (ft_putstr_c(to_print));
}

int		print_unsigned(int *infos, unsigned int str)
{
	char	*to_print;
	int		i;
	char	*tmp;

	i = 0;
	if (infos[3] == 'u')
		to_print = ft_uitoa(str);
	else if (infos[3] == 'x' || infos[3] == 'X')
		to_print = (infos[3] == 'x') ? dec_to_hex(str, 0) : dec_to_hex(str, 1);
	if (!str && !infos[2])
		to_print[0] = 0;
	print_int_precision(&to_print, infos);
	if (infos[1] && infos[2] < 0)
	{
		if (infos[1] >= 0 && infos[1] > (int)ft_strlen(to_print))
		{
			tmp = min_width(to_print, infos[1], infos[0]);
			free(to_print);
			to_print = tmp;
		}
	}
	return (ft_putstr_c(to_print));
}

int		print_char(int *infos, int str)
{
	char	*to_print;
	char	*tmp;
	int		count;

	if (str == 0)
		infos[1]--;
	to_print = malloc(2);
	to_print[0] = str;
	if (infos[1] > 0 && infos[1] > (int)ft_strlen(to_print))
	{
		tmp = min_width(to_print, infos[1], infos[0]);
		free(to_print);
		to_print = tmp;
	}
	count = ft_putstr_c(to_print);
	if (str == 0)
	{
		ft_putchar_fd(0, 1);
		count++;
	}
	return (count);
}
