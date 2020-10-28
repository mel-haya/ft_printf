/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:23:16 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/16 16:30:29 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(unsigned int num)
{
	int		output;
	long	a;

	if (num == 0)
		return (1);
	a = 1;
	output = 0;
	while (num / a)
	{
		output++;
		a *= 10;
	}
	return (output);
}

char		*ft_uitoa(unsigned int n)
{
	char			*result;
	int				i;
	int				len;

	i = 0;
	len = ft_numlen(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	len--;
	while (len >= 0)
	{
		result[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (result);
}
