/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:43:33 by adbouras          #+#    #+#             */
/*   Updated: 2024/06/05 11:47:12 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define GREEN "\e[0;32m"
# define RED "\033[0;31m"
# define BLUE "\e[0;34m"
# define RESET "\033[0m"

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

/*****	CLIENT	*******************************/
bool	check_pid(char *arg);
void	_ctob(char c, int pid);
void	ft_signal(int sig, siginfo_t *info, void *context);

/*****	SERVER	*******************************/
void	_btoc(int sig, pid_t pid);
void	_signal(int sig, siginfo_t *info, void *context);

#endif
