#include <string.h>
#include <stdio.h>

int main(void)
{
	char str[25] = "ALX Software Engineering";
	char *new_str = strtok(str, " ");

	while (new_str != NULL)
	{
		printf("%s\n", new_str);
		new_str = strtok(NULL, " ");
	}

	return (0);
}
