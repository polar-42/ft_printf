/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 15:59:01 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_uint(unsigned int nb)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr_uint(nb / 10);
		ft_putnbr_uint(nb % 10);
	}
	else
	{
		c = (nb + '0');
		write(1, &c, 1);
	}
}

static int	ft_putnbrf_uint(unsigned int nb)
{
	unsigned int		n;
	int					s;

	s = 0;
	n = nb;
	while (n >= 10)
	{
		n /= 10;
		s++;
	}
	s++;
	ft_putnbr_uint(nb);
	return (s);
}

int	ft_print_uint(va_list arguments)
{
	unsigned int	u;
	int				i;

	u = (unsigned int) va_arg(arguments, unsigned int);
	i = ft_putnbrf_uint(u);
	return (i);
}
