/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 15:46:22 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putstrf(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putstrf_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	ft_print_str(va_list arguments)
{
	char	*str;
	int		i;

	str = (char *) va_arg(arguments, char *);
	if (!str)
		i = ft_putstrf_null();
	else
		i = ft_putstrf(str);
	return (i);
}
