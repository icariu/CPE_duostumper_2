/*
** EPITECH PROJECT, 2020
** s_flag
** File description:
** s_flag
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char **fill_size_tab(int i, char **tab, int size, char *grid)
{
    static int c = 0;

    for (int j = 2; j < size * 2; j++) {
        if (j % 2 == 1)
            tab[i][j] = ' ';
        else {
            tab[i][j] = grid[c];
            c++;
        }
    }
    return (tab);
}

void s_flag(int size, char *grid, map_t *map, char **av)
{
    char **tab = malloc(sizeof(char *) * size + 3);

    if (tab == NULL)
        exit(84);
    for (int i = 0; i < size + 3; i++) {
        tab[i] = malloc(sizeof(char) * (4 + 2 * size));
        if (tab[i] == NULL)
            exit(84);
    }
    for (int i = 0; i < 3 + 2 * size; i++)
        tab[0][i] = '+';
    tab[0][size * 2 + 4] = '\0';
    for (int i = 1; i < size + 2; i++) {
        tab[i][0] = '|';
        tab[i][1] = ' ';
        tab = fill_size_tab(i, tab, size, grid);
        tab[i][size * 2 + 1] = '|';
        tab[i][size * 2 + 2] = '\0';
    }
    tab[size + 1] = tab[0];
    tab[size + 2] = NULL;
    main_loop(tab, map, av);
}
