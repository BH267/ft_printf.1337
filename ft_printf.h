/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:05:28 by habenydi          #+#    #+#             */
/*   Updated: 2024/11/15 15:31:15 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_puthexa(unsigned long n, char x);
int	ft_putunbr(unsigned int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_putnbr(int n);

#endif
