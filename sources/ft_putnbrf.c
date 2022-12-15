/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 15:57:21 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

static int	ft_putnbrf(int nb)
{
	int	s;
	int	n;

	s = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	n = nb;
	if (n < 0)
	{
		n *= -1;
		s++;
	}
	while (n >= 10)
	{
		n /= 10;
		s++;
	}
	s++;
	ft_putnbr(nb);
	return (s);
}

int	ft_print_int(va_list arguments)
{
	int		i;
	int		y;

	i = (int) va_arg(arguments, int);
	y = ft_putnbrf(i);
	return (y);
}
