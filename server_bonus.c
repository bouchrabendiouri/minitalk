

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 16)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("Error: wrong format\n");
		ft_putstr("./server\n");
		return (0);
	}
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	ft_putstr("Waiting for a message\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
	return (0);
}
