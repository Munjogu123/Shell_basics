#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac , char *av[])
{
	char *buffer;
	size_t chars;
	size_t buff_size = 1024;

	buffer = malloc(sizeof(char) * buff_size);
	if (buffer == NULL)
	{
		dprintf(STDOUT_FILENO, "Error allocating buffer\n");
		exit(98);
	}

	dprintf(STDOUT_FILENO, "$ ");
	chars = getline(&buffer, &buff_size, stdin);
	dprintf(STDOUT_FILENO, "%s", buffer);
	
	free(buffer);
	return (0);
}
