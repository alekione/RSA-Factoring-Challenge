#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

int main(int argc, char *argv[])
{
	char *ptr, *eptr;
	size_t count = 0;
	ssize_t ret;
	uintmax_t n, i;
	FILE *op;

	if (argc != 2)
	{
		printf("Usage: %s <file>", argv[0]);
		return (1);
	}
	op = fopen(argv[1], "r");
	while (true)
	{
		ret = getline(&ptr, &count, op);
		if (ret == -1)
			break;
		n = strtoull(ptr, &eptr, 10);
		if (n % 2 == 0)
			printf("%lu = %lu * %d\n", n, n / 2, 2);
		else
		{
			for (i = 3; i < n; i += 2)
			{
				if (n % i == 0)
				{
					printf("%lu = %lu * %lu\n", n, n / i, i);
					break;
				}
			}
		}
		free(ptr);
		ptr = NULL;
	}
	fclose(op);
	return (0);
}
