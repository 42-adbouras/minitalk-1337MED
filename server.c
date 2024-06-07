/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:03:20 by adbouras          #+#    #+#             */
/*   Updated: 2024/06/05 22:32:19 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;
	unsigned int		pid;

	ft_bzero(&sa, sizeof(sa));
	pid = getpid();
	ft_printf("%sProcess ID: %u%s\n", GREEN, pid, RESET);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

void	_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		_btoc(1, info->si_pid);
	else if (sig == SIGUSR2)
		_btoc(0, info->si_pid);
}

void	_btoc(int sig, pid_t pid)
{
	static int		c;
	static int		bit_ndx;
	static pid_t	old_pid;

	if (old_pid != pid)
	{
		bit_ndx = 0;
		c = 0;
	}
	old_pid = pid;
	if (sig == 1)
		c = c | (1 << bit_ndx);
	bit_ndx++;
	if (bit_ndx == 8)
	{
		write(1, &c, 1);
		bit_ndx = 0;
		c = 0;
	}
}
