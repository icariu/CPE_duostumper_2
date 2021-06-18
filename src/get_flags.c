/*
** EPITECH PROJECT, 2020
** get_flag
** File description:
** get_flag
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

void get_flags(char **av, map_t *map)
{
    if (map->ac >= 5) {
        if (strcmp(av[3], "-s") == 0) {
            map->s = 1;
            map->size = atoi(av[4]);
        } if (strcmp(av[3], "-w") == 0)
            map->w = 1;
    } if (map->ac == 7) {
        if (av[3] == av[5])
            exit(84);
        if (strcmp(av[5], "-s") == 0) {
            map->s = 1;
            map->size = atoi(av[6]);
        }if (strcmp(av[5], "-w") == 0) 
            map->w = 1;
    }
}
