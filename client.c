/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:13:49 by afournie          #+#    #+#             */
/*   Updated: 2026/01/20 10:46:16 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static volatile sig_atomic_t	g_received = 0;

static void	confirm(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
	else if (signal == SIGUSR2)
		g_received = 2;
}

void	send_bits(int pid, char i)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_received = 0;
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_received == 0)
			pause();
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
		return (ft_printf("Error\n"), 1);
	sa.sa_handler = confirm;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\n');
	while (g_received != 2)
		pause();
	ft_printf("Message reçu par le serveur !\n");
	return (0);
}
