/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:25 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/15 17:12:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char x)
{
	char	*lwbase;
	char	*upbase;
	int		cont;

	cont = 0;
	lwbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	if (n < 16)
	{
		if (x == 'x')
			cont += ft_putchar(*(n + lwbase));
		if (x == 'X')
			cont += ft_putchar(*(n + upbase));
	}
	if (n >= 16)
	{
		cont += ft_puthexa(n / 16, x);
		cont += ft_puthexa(n % 16, x);
	}
	return (cont);
}

int	ft_putunbr(unsigned int n)
{
	int	cont;

	cont = 0;
	if (n < 10)
		cont += ft_putchar('0' + n);
	else
	{
		cont += ft_putunbr(n / 10);
		cont += ft_putunbr(n % 10);
	}
	return (cont);
}
