#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			printf("%c\n", argv[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
