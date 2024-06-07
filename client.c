/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:04:53 by adbouras          #+#    #+#             */
/*   Updated: 2024/06/05 11:09:30 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		if (!check_pid(av[1]))
			return (write(2, RED "[Invalid PID]\n", 14 + sizeof(RED)), 1);
		i = 0;
		pid = atoi(av[1]);
		while (av[2][i])
		{
			_ctob(av[2][i], pid);
			i++;
		}
	}
	return (0);
}

bool	check_pid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i++]))
			return (false);
	}
	return (true);
}

void	_ctob(char c, int pid)
{
	int	bit_ndx;
	int	result;

	bit_ndx = 0;
	result = 0;
	while (bit_ndx < 8)
	{
		result = (c >> bit_ndx) & 1;
		if (result == 1)
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		else if (result == 0)
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		usleep(240);
		bit_ndx++;
	}
}
