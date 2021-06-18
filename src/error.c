/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include <stdlib.h>

void check_char_w(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 97 || str[i] > 122)
            exit(84);
}
