/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:16:03 by adouay            #+#    #+#             */
/*   Updated: 2022/06/13 18:35:02 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef	struct s_args{
	int		pid;
	char	*str;
}	t_args;

void	sig_bit(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args->str[j])
	{
		printf("%c\n", args->str[j]);
		while(i < 8)
		{
			if((args->str[j] & 1 << i))
				kill(args->pid, SIGUSR1);
			else
				kill(args->pid, SIGUSR2);
			printf("%d\n", i);
			usleep(5000);
			i++;
		}
		i = 0;
		j++;
	}
}

void	parse_args(t_args *args, int pid, char *str)
{
	args->pid = pid;
	args->str = str;
}

int main(int argc, char **argv)
{
	t_args	args;

	if(argc != 3)
		return (0);
	parse_args(&args, 292545, argv[2]);
	sig_bit(&args);
/*	int	i = 0;
	char *str = "qwet";
	while(*str)
	{
		printf(" char : %c\n", *str);
		while(i < 8)
		{
			printf("%d\n", (*str & 1 << i) ? 1 : 0);
			i++;
		}
		printf("----------------\n");
		i = 0;
		str++;
	}
*/
	return (0);
}