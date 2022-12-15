/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 12:56:17 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_str(va_list arguments);
int		ft_print_char(va_list arguments);
int		ft_print_uint(va_list arguments);
int		ft_print_hexa_min(va_list arguments);
int		ft_print_hexa_maj(va_list arguments);
int		ft_print_int(va_list arguments);
int		ft_putaddr(va_list arguments);
int		ft_putper(void);

#endif
