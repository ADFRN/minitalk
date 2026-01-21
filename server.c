/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:14:01 by afournie          #+#    #+#             */
/*   Updated: 2026/01/21 13:11:46 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	i <<= 1;
	if (signal == SIGUSR1)
		i |= 1;
	bit++;
	if (bit == 8)
	{
		if (i == '\n')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Error - No arguments required here\n"), 0);
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argc == 1)
		pause();
	return (0);
}
