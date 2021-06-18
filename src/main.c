/*
** EPITECH PROJECT, 2020
** CPE_duostumper_2_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char **fill_my_tab(int i, char **tab, char **av)
{
    static int c = 0;

    for (int j = 2; j < 10; j++) {
        if (j % 2 == 1)
            tab[i][j] = ' ';
        else {
            tab[i][j] = av[2][c];
            c++;
        }
    }
    return (tab);
}

void main_loop(char **tab, map_t *map, char **av)
{
    char *term = NULL;
    size_t len = 0;
    int read;

    if (map->ac == 5 && strcmp(av[3], "-w") == 0) {
        check_word(tab, av[4], *map);
        exit(0);
    }
    display_tab(tab);
    while (1) {
        write(1, "> ", 2);
        read = getline(&term, &len, stdin);
        if (read == -1)
            exit(0);
        check_word(tab, term, *map);
    }
}

void simple_boggle(char **av, map_t *map)
{
    char **tab = malloc(sizeof(char *) * 7);

    if (strlen(av[2]) != 16 || tab == NULL)
        exit(84);
    for (int i = 0; i < 6; i++) {
        tab[i] = malloc(sizeof(char) * 12);
        if (tab[i] == NULL)
            exit(84);
    }
    tab[0] = "+++++++++++\0";
    for (int i = 1; i < 5; i++) {
        tab[i][0] = '|';
        tab[i][1] = ' ';
        tab = fill_my_tab(i, tab, av);
        tab[i][10] = '|';
        tab[i][11] = '\0';
    }
    tab[5] = "+++++++++++\0";
    tab[6] = NULL;
    main_loop(tab, map, av);
}

void check_error(int ac, char **av)
{
    for (int i = 0; av[2][i]; i++)
        if (av[2][i] < 97 || av[2][i] > 122)
            exit(84);
    if (ac == 5 && strcmp(av[3], "-w") != 0 && strcmp(av[3], "-s") != 0)
        exit(84);
    if (ac == 7 && strcmp(av[5], "-w") != 0 && strcmp(av[5], "-s") != 0)
        exit(84);
    for (int i = 1; i < ac; i++) {
        if (strcmp(av[i], "-s") == 0 && atoi(av[i + 1]) <= 0)
            exit (84);
        if (strcmp(av[i], "-w") == 0)
            check_char_w(av[i + 1]);
    }
}

int main(int ac, char **av)
{
    map_t map;

    map.ac = ac;
    if (ac == 1 || ac > 7 || ac % 2 == 0 ||
        (ac > 1 && strcmp(av[1], "-g") != 0))
        return (84);
    check_error(ac, av);
    init_struct(&map);
    get_flags(av, &map);
    if (map.s == 0)
        simple_boggle(av, &map);
    return (0);
}
