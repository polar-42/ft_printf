/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:45:59 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 15:45:36 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_hexa_min(long long unsigned int nb, char *base_hexa)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa_min(nb / 16, base_hexa);
		ft_putnbr_hexa_min(nb % 16, base_hexa);
	}
	else
		write(1, &base_hexa[nb], 1);
}

static int	ft_putnbrf_hexa_min(long long unsigned int nb)
{
	long long unsigned int	s;
	long long unsigned int	n;

	s = 0;
	n = nb;
	while (n >= 16)
	{
		n /= 16;
		s++;
	}
	write(1, "0x", 2);
	ft_putnbr_hexa_min(nb, "0123456789abcdef");
	return (s + 3);
}

static int	ft_putaddr_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_putaddr(va_list arguments)
{
	long long unsigned int	u;
	int						i;

	u = (long long unsigned int) va_arg(arguments, long long unsigned int);
	if (!u)
		i = ft_putaddr_nil();
	else
		i = ft_putnbrf_hexa_min(u);
	return (i);
}
