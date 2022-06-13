/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:43:58 by adouay            #+#    #+#             */
/*   Updated: 2022/06/13 18:34:39 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

typedef	struct s_char{
	int 	ch;
	int	current_bit;
}	t_char;

void	sig_handler(int	signum)
{
	static t_char	c = {0, 0};

	if (signum == SIGUSR1)
		c.ch |= 1 << c.current_bit;
	c.current_bit++;
	if (c.current_bit == 8)
	{
		printf("%c\n", c.ch);
		c.ch = 0;
		c.current_bit = 0;
	}
}
int	main()
{
	int id = getpid();
	signal(SIGUSR1,	sig_handler);
	signal(SIGUSR2,	sig_handler);
	printf("server pid : %d\n", id);
	while(42)
		pause();
	return(0);
}