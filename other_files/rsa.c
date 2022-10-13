#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

bool isprime(uintmax_t n)
{
	uintmax_t i;

	if (n == 2 || n == 3)
		return (true);
	if (n <=1 || n % 2 == 0 || n % 3 == 0)
		return (false);
	for (i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	char *ptr, *eptr;
	size_t count = 0;
	ssize_t ret;
	uintmax_t n, i;
	FILE *op;
	bool done;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}
	op = fopen(argv[1], "r");
	while (true)
	{
		ret = getline(&ptr, &count, op);
		if (ret == -1)
			break;
		n = strtoull(ptr, &eptr, 10);
		free(ptr);
		ptr = NULL;
		if (n % 2 == 0 && isprime(n / 2))
		{
			printf("%lu=%lu*%d\n", n, n / 2, 2);
			continue;
		}
		if (n % 3 == 0 && isprime(n / 3))
		{
			printf("%lu=%lu*%d\n", n, n / 3, 3);
			continue;
		}
		done = false;
		for (i = 5; i * i <= n; i += 6)
		{
			if (n % i == 0 && isprime(n / i))
			{
				printf("%lu=%lu*%lu\n", n, n / i, i);
				done = true;
				break;
			}
			if (n % (i + 2) == 0 && isprime(n / (i + 2)))
			{
				printf("%lu=%lu*%lu\n", n, n / (i + 2), i + 2);
				done = true;
				break;
			}
		}
		if (!(done))
			printf("%lu=%lu*%d\n", n, n, 1);
	}
	free(ptr);
	fclose(op);
	return (0);
}
