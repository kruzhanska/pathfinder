#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_road {
    char *isl1;
    char *isl2;
    int dist;
    struct s_road *next;
}         t_road;

typedef struct s_adj {
    int where;
    int weight;
    struct s_adj *next;
}         t_adj;

typedef struct s_route {
    int point;
    struct s_route *next;
}         t_route;

typedef struct s_stack {
	t_route *route;
	int next_point;
	int weight;
	struct s_stack *next;
}         t_stack;

char **mx_printerr(int argc, char *argv, int *num);
void mx_not_exist_or_empty(char *argv);
void mx_line_not_valid(char **arr);
void mx_first_line_not_valid(char *argv);
char **mx_invalid_number(char **arr, int len_str, int *num_isl);
t_road *mx_new_list(char *isl1, char *isl2, int dist);
void mx_push_list(t_road **list, char *isl1, char *isl2, int dist);
t_road *mx_arr_to_list(char **arr, int i);
int **mx_create_matrix(int num_isl);
void mx_pathfinder(t_road *list, char **arr, int num_isl);
void mx_fil_matrix(int ***arr_W, t_road *list, char **arr);
void mx_algorithm(int ***arr_W, int num_isl);
t_adj **mx_adjacency(t_road *list, char **arr, int num_isl);
void mx_depth_search(t_adj **Adj, int **arr_W, char **arr, int num_isl);
void mx_final_print(t_route **route, int **arr_W, char **arr);
void mx_stack(t_stack **stack, int next, int weight);
void mx_del_first_stack(t_stack **stack);

#endif
