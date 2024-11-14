/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:58:37 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/14 17:34:56 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_format(char sp, va_list list)
{
	int	cont;

	cont = 0;
	if (sp == 's')
		cont = ft_putstr_fd(va_arg(list, char *), 1);
	if (sp == 'd' || sp == 'i')
		cont = ft_putnbr_fd(va_arg(list, int), 1);
	if (sp == 'c')
		cont = ft_putchar_fd(va_arg(list, int), 1);
	if (sp == '%')
		cont = ft_putchar_fd('%', 1);
	if (sp == 'x' || sp == 'X')
		cont = ft_puthexa(va_arg(list, long), sp);
	if (sp == 'p')
	{
		ft_putstr_fd("0x", 1);
		cont = 2 + ft_puthexa((va_arg(list, int)), 'x');
	}
	if (sp == 'u')
		cont = ft_putunbr(va_arg(list, unsigned int));
	return (cont);
}

int	ft_printf(const char *f, ...)
{
	va_list	list;
	char	*sp;
	int		cont;

	va_start(list, f);
	cont = 0;
	sp = (char *) f;
	while (*sp)
	{
		if (*sp == '%')
			cont += ft_format(*(++sp), list);
		else
			cont += ft_putchar_fd(*sp, 1);
		sp++;
	}
	va_end(list);
	return (cont);
}
