/*
** EPITECH PROJECT, 2020
** free_tab
** File description:
** free_tab
*/

#include "stdlib.h"
#include "stddef.h"

void my_free_tab(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
