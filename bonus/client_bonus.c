/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:04:53 by adbouras          #+#    #+#             */
/*   Updated: 2024/06/05 11:49:29 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					i;
	int					pid;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_signal;
	sigaction(SIGUSR1, &sa, NULL);
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
		_ctob(av[2][i], pid);
	}
	return (0);
}

void	ft_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		ft_printf("%s[THE SERVER HAS RECIEVED THE MESSAGE]%s\n", BLUE, RESET);
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
