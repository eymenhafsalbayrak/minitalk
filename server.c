/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:44:19 by ealbayra          #+#    #+#             */
/*   Updated: 2023/03/31 19:59:02 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	}
}

static void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	bitstorage(int poolsignal)
{
	static unsigned char	x;
	static int				i;

	if (poolsignal == SIGUSR1)
		x = x | 1;
	i++;
	if (i == 8)
	{
		write(1, &x, 1);
		i = 0;
		x = 0;
	}
	x = x << 1;
}

int	main(void)
{
	ft_putstr("Server started with PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal (SIGUSR1, bitstorage);
	signal (SIGUSR2, bitstorage);
	while (1)
		pause();
	return (0);
}
