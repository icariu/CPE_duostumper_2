/*
** EPITECH PROJECT, 2020
** CPE_duostumper_2_2019
** File description:
** check_word.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void verif_if_word_ok(size_t x, char **tab, map_t map)
{
    if (x == strlen(map.word) - 1) {
        display_tab(tab);
        exit(0);
    }
}

void looking_for_word(int i, int j, char **tab, map_t map)
{
    size_t x = 1;

    if (tab[i][j] != map.word[0])
        return;
    for (; map.word[x]; x++) {
        tab[i][j] = tab[i][j] - 32;
        if (tab[i - 1] != NULL && tab[i - 1][j] == map.word[x]) {
            i--;
            continue;
        } if (tab[i + 1] != NULL && tab[i + 1][j] == map.word[x]) {
            i++;
            continue;
        } if (tab[i][j + 2] == map.word[x]) {
            j += 2;
            continue;
        } if (tab[i][j - 2] == map.word[x]) {
            j -= 2;
            continue;
        }
        break;
    }
    verif_if_word_ok(x, tab, map);
}

void reset_tab(char **tab)
{
    for (int i = 1; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++)
            if (tab[i][j] > 64 && tab[i][j] < 91)
                tab[i][j] += 32;
}

void check_word(char **tab, char *word, map_t map)
{
    map.word = word;
    if (map.ac == 5)
        map.word = strcat(map.word, "\n");
    for (int i = 1; tab[i]; i++)
        for (int j = 0; tab[i][j]; j++) {
            reset_tab(tab);
            looking_for_word(i, j, tab, map);
        }
    write(1, "The word \"", 10);
    write(1, word, strlen(word) - 1);
    printf("\" is not in the grid.\n");
}
