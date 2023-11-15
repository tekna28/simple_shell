#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * _strlen - returns the length of a string.
 *
 *@s: string.
 * Return: length of a string (Success)
 */
int _strlen(char *s)
{
int i = 0;
while (*s != '\0')
{
i++;
s++;
}
return (i);
}

/**
 * _strcpy - copies the string pointed to by src, including the
 *terminating null byte (\0), to the buffer pointed to by dest.
 *
 *@dest: pointer to a char.
 *@src: pointer to a char.
 * Return: pointer to dest (Success)
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; i < _strlen(src); i++)
{
*(dest + i) = *(src + i);
}

dest[i++] = '\0';
return (dest);
}
/**
 * _strdup - duplicates a string.
 *
 *@str: pointer to a char.
 * Return: duplicated string (Success)
 */
char *_strdup(const char *str)
{
char *ptr;
int i, len = 0;
if (str == NULL)
return (NULL);
while (*str != '\0')
{
len++,
str++;
}
str = str - len;
ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);
for (i = 0; i <= len; i++)
ptr[i] = str[i];
return (ptr);
}
