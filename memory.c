#include "shell.h"

/**
 * cfree - freeing  pointer
 * cfree - and NULLs the address
 * @ptr:  the address of the pointer to free
 *
 * Return: 1 when  freed, otherwise 0.
 */
int cfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0
