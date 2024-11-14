/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:25 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/14 17:46:52 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthexa(long n, char x)
{
	char	*lwbase;
	char	*upbase;
	int		cont;

	cont = 0;
	lwbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	if (n < 0)
	{
		cont += ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n < 16)
	{
		if (x == 'x')
			cont += ft_putchar_fd(*(n + lwbase), 1);
		if (x == 'X')
			cont += ft_putchar_fd(*(n + upbase), 1);
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
		cont += ft_putchar_fd('0' + n, 1);
	else
	{
		cont += ft_putunbr(n / 10);
		cont += ft_putunbr(n % 10);
	}
	return (cont);
}
