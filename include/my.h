/*
** EPITECH PROJECT, 2019
** my lib
** File description:
** lib <alizee.soussan@epitech.eu>
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_isneg(int n);
int my_nblen(int nb);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
int my_show_word_array(char * const *tab);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_itoa(int nb);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strcapitalize(char *str);
char *my_strcat_slash(char *src, char *dest);
char *my_strcat(char *src, char *dest);
char *my_strcatchar(char *ssrc, char c);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str, char charact);

typedef struct map {
    char **map;
    int ac;
    int s;
    int w;
    char *word;
    int size;
} map_t;

void display_tab(char **tab);
void check_word(char **tab, char *term, map_t map);
void check_char_w(char *str);
void main_loop(char **tab, map_t *map, char **av);
void init_struct(map_t *map);
void get_flags(char **av, map_t *map);

#endif /* MY_H */
