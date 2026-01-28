/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:13:49 by afournie          #+#    #+#             */
/*   Updated: 2026/01/28 14:20:19 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

int		g_received = 0;

void	confirm(int signal)
{
	if (signal == SIGUSR2)
		g_received = 1;
	if (signal == SIGUSR1)
		g_received = 2;
}

void	send_bits(int pid, char i)
{
	int	bit;
	int	timeout;

	bit = 7;
	while (bit >= 0)
	{
		g_received = 0;
		if ((i >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		timeout = 0;
		while (g_received == 0 && timeout < 1000)
		{
			usleep(100);
			timeout++;
		}
		if (g_received == 0)
		{
			ft_printf("Error - No response from server (PID: %d)\n", pid);
			exit(1);
		}
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (ft_printf("Error - PID required first, then the message\n"), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Error - You trying something wrong\n"), 1);
	signal(SIGUSR1, confirm);
	signal(SIGUSR2, confirm);
	i = 0;
	while (argv[2][i])
		send_bits(pid, argv[2][i++]);
	send_bits(pid, '\0');
	ft_printf("Copy\n");
	return (EXIT_SUCCESS);
}
