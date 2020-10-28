/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:39:03 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/22 02:09:17 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_num_arg(char **specifier, va_list vl)
{
	int output;

	if (**specifier == '*')
		output = va_arg(vl, int);
	else if (ft_isdigit(**specifier))
		output = ft_atoi(*specifier);
	else
		output = 0;
	return (output);
}

int		*get_flags(char *specifier, va_list vl)
{
	int *output;

	output = malloc(4 * sizeof(unsigned int));
	specifier++;
	output[0] = get_min_width_flag(specifier);
	while (*specifier == '-' || *specifier == '0')
		specifier++;
	output[1] = get_num_arg(&specifier, vl);
	if (output[1] < 0)
	{
		output[1] = -output[1];
		output[0] = 2;
	}
	while (ft_isdigit(*specifier) || *specifier == '*')
		specifier++;
	output[2] = -1;
	if (*specifier == '.')
	{
		specifier++;
		output[2] = get_num_arg(&specifier, vl);
		while (ft_isdigit(*specifier) || *specifier == '*')
			specifier++;
	}
	output[3] = *specifier;
	return (output);
}

char	*get_specifier(const char *buff)
{
	int		i;
	char	*output;

	i = 1;
	while (!ft_isalpha_percent(buff[i]))
		i++;
	output = malloc(i + 2);
	if (!output)
		return (NULL);
	output[0] = '%';
	i = 1;
	while (!ft_isalpha_percent(buff[i]))
	{
		output[i] = buff[i];
		i++;
	}
	output[i] = buff[i];
	output[i + 1] = 0;
	return (output);
}

char	*min_width(char *str, int width, int flag)
{
	int		spaces;
	char	value;
	char	*sp_str;
	char	*output;

	value = 32;
	if ((int)ft_strlen(str) > width)
		return (str);
	spaces = width - ft_strlen(str);
	if (flag == 1)
		value = 48;
	sp_str = malloc(spaces + 1);
	sp_str[spaces] = 0;
	sp_str = ft_memset(sp_str, value, spaces);
	if (!flag || flag == 1)
		output = (ft_strjoin(sp_str, str));
	else
		output = (ft_strjoin(str, sp_str));
	free(sp_str);
	return (output);
}

int		get_min_width_flag(char *specifier)
{
	int length;

	length = ft_strlen(specifier);
	if (specifier[0] == 45)
		return (2);
	else if (specifier[0] == 48)
		return (1);
	else
		return (0);
}
