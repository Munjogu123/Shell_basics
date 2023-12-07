#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *str, int *num)
{
	char **arr, *dup, *piece;
	int i;

	if (str == NULL)
		return (NULL);

	dup = strdup(str);
	piece = strtok(dup, " ");
	while (piece != NULL)
	{
		if ((*piece) == '\n')
		{
			piece = strtok(NULL, " ");
			continue;
		}
		(*num)++;
		piece = strtok(NULL, " ");
	}

	arr = malloc(sizeof(char *) * (*num));
	piece = strtok(str, " ");
	i = 0;
	while (piece != NULL)
	{
		if ((*piece) == '\n')
		{
			piece = strtok(NULL, " ");
			continue;
		}
		arr[i] = malloc(sizeof(char) * (strlen(piece) + 1));
		strcpy(arr[i], piece);
		i++;
		piece = strtok(NULL, " ");
	}

	if (dup)
		free(dup);

	return (arr);
}

int main(void)
{
	char str[] = "Test string";
	int i, num = 0;
	char **result = split_string(str, &num);

	for (i = 0; i < num; i++)
	{
		printf("word[%d]: %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);

	return (0);
}
