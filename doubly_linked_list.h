//
// Created by merlin on 4/3/2022.
//

#ifndef PROJECT4_DOUBLY_LINKED_LIST_H
#define PROJECT4_DOUBLY_LINKED_LIST_H

#define MAX_VALUE 2000
#define MIN_VALUE 1
#define ERROR_VALUE MIN_VALUE - 1

typedef struct node_s
{
    int data;
    struct node_s *next;
    struct node_s *prev;
}node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} list_t;

int forward_length(list_t list);
list_t *create_empty_list();
void delete(list_t *list, int target);
int grab_the_head(list_t *list);
int grab_the_tail(list_t *list);
node_t *find(list_t list, int target);
void insert_at_head(list_t *list, int data_val);
void insert_at_tail(list_t *list, int data_val);
void insert_in_order(list_t *list, int data_val);
void print_list(list_t list);

#endif //PROJECT4_DOUBLY_LINKED_LIST_H
