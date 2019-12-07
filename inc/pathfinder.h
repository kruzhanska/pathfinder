#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_path {
    char *isl1;
    char *isl2;
    int dist;
    struct s_path *next;
}         t_path;

typedef struct s_turn {
    int turn;
    struct s_turn *next;
}         t_turn;

char **mx_printerr(int argc, char *argv, int *num);
void mx_not_exist_or_empty(char *argv);
void mx_line_not_valid(char **arr);
void mx_first_line_not_valid(char *argv);
char **mx_invalid_number(char **arr, int len_str, int *num_isl);
t_path *mx_new_list(char *isl1, char *isl2, int dist);
void mx_push_list(t_path **list, char *isl1, char *isl2, int dist);
t_path *mx_arr_to_list(char **arr);
int **mx_create_matrix(int num_isl);
t_path *mx_pathfinder(t_path *list, char **arr, int num_isl);
void mx_fil_matrix(int ***arr_W, t_turn ****arr_H, t_path *list, char **arr);
void mx_algorithm(int ***arr_W, t_turn ****arr_H, int num_isl);
t_turn ***mx_matrix_H(int size);

#endif
