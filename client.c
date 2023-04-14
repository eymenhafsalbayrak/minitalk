/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbayra <ealbayra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:46:10 by ealbayra          #+#    #+#             */
/*   Updated: 2023/03/31 19:58:59 by ealbayra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	nbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * sign);
}

void	signalcheck(int pid, char *data)
{
	int				i;
	int				j;
	unsigned char	bit;

	j = 0;
	while (data[j])
	{
		i = 7;
		bit = data[j];
		while (i >= 0)
		{
			if ((bit >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(WAIT_CRON);
			i--;
		}
		j++;
	}	
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*data;

	data = argv[2];
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signalcheck(pid, data);
	}
}
