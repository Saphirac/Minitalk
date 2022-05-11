/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:49:00 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/05/12 01:49:36 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(int ac, char **av)
{
	if (ac != 3)
		return (1);
	if (ft_atoi(av[1]) <= 0)
		return (1);
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error : wrong pid\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_send_message(int pid, char *msg)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	size = ft_strlen(msg);
	while (i <= size)
	{
		j = 7;
		while (j > -1)
		{	
			// action pour sigusr1
			if ((msg[i] >> j) & 1)
				if (kill(pid, SIGUSR1) < 0)
					ft_error();
			// action pour sigusr2
			if (!((msg[i] >> j) & 1))
				if (kill(pid, SIGUSR2) < 0)
					ft_error();
			j--;
			usleep(500);
		}
		i++;
	}
}

int	main (int ac, char **av)
{
	if (ft_check(ac, av) == 1)
		return (1);
	ft_send_message(ft_atoi(av[1]), av[2]);
	return (0);
}