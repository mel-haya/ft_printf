/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-haya <mel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:44:23 by mel-haya          #+#    #+#             */
/*   Updated: 2019/11/22 01:44:05 by mel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strdup(const char *src);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *dst, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *str, char c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *str, const char *word, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(char *s);
char			*ft_strmapi(char const *s, int (*f)(int));
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
char			*ft_uitoa(unsigned int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isascii(int c);
char			*ft_strtrim(char const *s1, char const *set);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
#endif
