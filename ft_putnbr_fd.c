/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:36:25 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/14 17:47:49 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		cont += ft_putchar_fd('-', fd);
	}
	if (n < 10)
		cont += ft_putchar_fd('0' + n, fd);
	else
	{
		cont += ft_putnbr_fd(n / 10, fd);
		cont += ft_putnbr_fd(n % 10, fd);
	}
	return (cont);
}
