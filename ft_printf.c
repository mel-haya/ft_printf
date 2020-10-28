/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:27:08 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/23 06:23:43 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		get_function(char c, int *infos, va_list vl)
{
	int count;

	count = 0;
	if (c != '%')
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	if (infos[3] == 's')
		count += print_str(infos, va_arg(vl, char *));
	else if (infos[3] == 'd' || infos[3] == 'i')
		count += print_int(infos, va_arg(vl, int));
	else if (infos[3] == 'p')
		count += print_pointer(infos, va_arg(vl, void *));
	else if (infos[3] == 'u' || infos[3] == 'x' || infos[3] == 'X')
		count += print_unsigned(infos, va_arg(vl, unsigned int));
	else if (infos[3] == 'c' || infos[3] == '%')
		count += print_char(infos, (infos[3] == 'c') ? va_arg(vl, int) : '%');
	else
		count = 0;
	return (count);
}

int		ft_printf(const char *buff, ...)
{
	va_list	vl;
	int		i;
	int		*infos;
	int		count;
	char	*specifier;

	i = 0;
	count = 0;
	va_start(vl, buff);
	while (buff[i])
	{
		specifier = (buff[i] == '%') ? get_specifier(buff + i) : NULL;
		if (buff[i] == '%')
			infos = get_flags(specifier, vl);
		count += get_function(buff[i], infos, vl);
		if (buff[i] == '%')
		{
			i += ft_strlen(specifier) - 1;
			free(infos);
			free(specifier);
		}
		i++;
	}
	va_end(vl);
	return (count);
}
