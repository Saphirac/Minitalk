/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:04:23 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/05/12 01:52:42 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_get_message(int signal)
{
	static char	c = 0x00;
	static int	size = 7;

	if (signal == SIGUSR1)
	{
		c = c + (1 << size);
		size--;
	}
	if (signal == SIGUSR2)
		size--;
	if (size < 0)
	{
		ft_putchar_fd(c, 1);
		if (!c)
			ft_putchar_fd('\n', 1);
		c = 0x00;
		size = 7;
	}
}
int	main()
{
	ft_putstr_fd("Pid of server : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, ft_get_message);
	signal(SIGUSR2, ft_get_message);
	while (1)
		pause();
}