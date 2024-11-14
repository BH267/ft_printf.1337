/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:25 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/13 12:04:58 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return ;
}

void	ft_puthexa(long n, char x)
{
	char	*lwbase;
	char	*upbase;

	lwbase = "0123456789abcdef";
	upbase = "0123456789ABCDEF";
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	if (n < 16)
	{
		if (x == 'x')
			ft_putchar_fd(*(n + lwbase), 1);
		if (x == 'X')
			ft_putchar_fd(*(n + upbase), 1);
	}
	if (n >= 16)
	{
		ft_puthexa(n/16, x);
		ft_puthexa(n%16, x);
	}

}

void	ft_putunbr(unsigned int n)
{
	if (n < 10)
		ft_putchar_fd('0' + n, 1);
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}
