/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:49:00 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/05/12 02:01:13 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (1);
	if (ft_atoi(av[1]) <= 0)
		return (1);
	while (av[1][i])
	{
		if (ft_isdigit(av[1][i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error.\n", 2);
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
			if ((msg[i] >> j) & 1)
				if (kill(pid, SIGUSR1) < 0)
					ft_error();
			if (!((msg[i] >> j) & 1))
				if (kill(pid, SIGUSR2) < 0)
					ft_error();
			j--;
			usleep(30);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ft_check(ac, av) == 1)
	{
		ft_putstr_fd("Error.\n", 2);
		return (1);
	}
	ft_send_message(ft_atoi(av[1]), av[2]);
	return (0);
}
