/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:58:37 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/18 10:43:51 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char sp, va_list list)
{
	int	cont;

	cont = 0;
	if (sp == 's')
		cont = ft_putstr(va_arg(list, char *));
	if (sp == 'd' || sp == 'i')
		cont = ft_putnbr(va_arg(list, int));
	if (sp == 'c')
		cont = ft_putchar(va_arg(list, int));
	if (sp == '%')
		cont = ft_putchar('%');
	if (sp == 'x' || sp == 'X')
		cont = ft_puthexa(va_arg(list, unsigned int), sp);
	if (sp == 'p')
	{
		cont = ft_putstr("0x");
		cont += ft_puthexa((va_arg(list, unsigned long)), 'x');
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

	if (!f || write(1, 0, 0) == -1)
		return (-1);
	va_start(list, f);
	cont = 0;
	sp = (char *) f;
	while (*sp)
	{
		if (*sp == '%')
		{
			if (*(sp + 1) == '\0')
				return (cont);
			cont += ft_format(*(++sp), list);
		}
		else
			cont += ft_putchar(*sp);
		sp++;
	}
	va_end(list);
	return (cont);
}
