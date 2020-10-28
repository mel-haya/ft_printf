/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:45:07 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/23 06:20:59 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

char	*dec_to_hex(unsigned long long nb, int maj);
int		get_min_width_flag(char *specifier);
int		ft_printf(const char *buff, ...);
int		get_num_arg(char **specifier, va_list vl);
int		*get_flags(char *specifier, va_list vl);
char	*get_specifier(const char *buff);
char	*min_width(char *str, int width, int flag);
char	hex_digit(int a);
char	*dec_to_hex(unsigned long long nb, int maj);
int		print_str(int *infos, char *str);
int		print_int(int *infos, int str);
int		print_pointer(int *infos, void *str);
int		print_unsigned(int *infos, unsigned int str);
int		print_char(int *infos, int str);
int		ft_isalpha_percent(int c);
int		get_num_arg(char **specifier, va_list vl);
int		*get_flags(char *specifier, va_list vl);
char	*get_specifier(const char *buff);
char	*min_width(char *str, int width, int flag);
int		get_min_width_flag(char *specifier);
int		ft_putstr_c(char *str);
void	print_int_precision(char **to_print, int *infos);
int		print_negative_int(int *infos, int str);
#endif
