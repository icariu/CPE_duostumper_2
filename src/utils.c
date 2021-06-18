/*
** EPITECH PROJECT, 2020
** CPE_duostumper_2_2019
** File description:
** utils.c
*/

#include <stdio.h>
#include "my.h"

void display_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}

void init_struct(map_t *map)
{
    map->s = 0;
    map->w = 0;
}
