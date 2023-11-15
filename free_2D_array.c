#include <stdio.h>
#include <stddef.h>
#include "main.h"

/**
 * free_2D_array - frees 2D array.
 *
 *@array: 2D array.
 * Return: no return (Success)
 */
void free_2D_array(char **array)
{
unsigned int i = 0;

/* if array is empty*/
if (array == NULL)
return;

while (array[i])
{
free(array[i]);
++i;
}

free(array);
}
