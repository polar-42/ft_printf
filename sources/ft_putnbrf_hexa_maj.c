/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf_hexa_maj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:46:13 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/10/26 16:32:06 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr_hexa_maj(unsigned int nb, char *base_hexa)
{
	if (nb >= 16)
	{
		ft_putnbr_hexa_maj(nb / 16, base_hexa);
		ft_putnbr_hexa_maj(nb % 16, base_hexa);
	}
	else
		write(1, &base_hexa[nb], 1);
}

static int	ft_putnbrf_hexa_maj(unsigned int nb)
{
	unsigned int	s;
	unsigned int	n;

	s = 0;
	n = nb;
	while (n >= 16)
	{
		n /= 16;
		s++;
	}
	s++;
	ft_putnbr_hexa_maj(nb, "0123456789ABCDEF");
	return (s);
}

int	ft_print_hexa_maj(va_list arguments)
{
	unsigned int	i;
	unsigned int	y;

	i = (unsigned int) va_arg(arguments, unsigned int);
	y = ft_putnbrf_hexa_maj(i);
	return (y);
}
