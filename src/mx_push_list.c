#include "pathfinder.h"	

void mx_push_list(t_road **list, char *isl1, char *isl2, int dist) {
    t_road *new = mx_new_list(isl1, isl2, dist);

    if (*list == NULL)
        *list = new;
    else {
        t_road *last = *list;
        
        while(last->next != NULL)
            last = last->next;
        last->next = new;
    }
}
