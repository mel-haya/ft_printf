/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:42:10 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/22 15:02:42 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	hex_digit(int a, int maj)
{
	if (a < 10)
		return (48 + a);
	else
		return (maj ? 55 + a : 87 + a);
}

char	*dec_to_hex(unsigned long long nb, int maj)
{
	char				*output;
	unsigned long long	i;
	int					size;
	char				*zero;

	i = nb;
	if (!i)
	{
		zero = ft_calloc(2, 1);
		zero[0] = '0';
		return (zero);
	}
	size = 0;
	while (i > 0 && (++size))
		i /= 16;
	if (!(output = malloc(size + 1)))
		return (NULL);
	output[size--] = 0;
	while (nb > 0 && (output[size--] = hex_digit(nb % 16, maj)))
		nb /= 16;
	return (output);
}
