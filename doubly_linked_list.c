//
// Created by merlin on 4/3/2022.
//
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "doubly_linked_list.h"


int max(int first, int second) {
    if (first > second)
    {
        return first;
    }
    return second;
}

int forward_length(list_t list)
{
    node_t *p = list.head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int backward_length(list_t list)
{
    node_t *p = list.tail;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->prev;
    }
    return count;
}
void check_list_structure(list_t list)
{
    if ((list.head == NULL) || (list.tail == NULL))
    {
        assert((list.head == NULL) && (list.tail == NULL));
    } else
    {
        assert(forward_length(list) == backward_length(list));
    }
}

void check_ordered_list(list_t list)
{
    check_list_structure(list);
    node_t *node ;
    if (list.head != NULL && list.tail != NULL)
    {
        node = list.head;
        while(node->next != NULL)
        {
         assert(node->data <= node->next->data);
        }
    }
}

list_t *create_empty_list()
{
    list_t *result =  calloc(1, sizeof(list_t));

    //post-conditions:
    result->head= NULL;
    result->tail= NULL;
    assert(result->head == NULL);
    assert(result->tail == NULL);
    return result;
}
node_t *create_empty_node(int data_val)
{
    node_t *node = calloc(1, sizeof(node_t));
    node->data= data_val;
    node->next= NULL;
    node->prev= NULL;
    return node;
}

void delete(list_t *list, int target)
{
    int pre_length = forward_length(*list);

    // Put your code for delete here

    check_list_structure(*list);
    assert(forward_length(*list) == max(0, pre_length - 1));
}

int delete_from_head(list_t *list)
{
    int pre_length = forward_length(*list);

    // Put your code for delete here

    check_list_structure(*list);
    assert(forward_length(*list) == max(0, pre_length - 1));
}
int delete_from_tail(list_t *list)
{
    int pre_length = forward_length(*list);

    // Put your code for delete here

    check_list_structure(*list);
    assert(forward_length(*list) == max(0, pre_length - 1));
}

void insert_at_head(list_t *list, int data_val) {
    assert(list != NULL);
    assert((data_val >= MIN_VALUE) && (data_val <= MAX_VALUE));
    int pre_length = forward_length(*list);

    node_t *node = create_empty_node(data_val);
    if (list->head != NULL) {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    } else {
        list->head = node;
        list->tail = node;
    }

    assert(forward_length(*list) == pre_length + 1);
    assert(list->head->data == data_val);
    check_list_structure(*list);
}

void insert_at_tail(list_t *list, int data_val)
{
    assert(list != NULL);
    assert((data_val >= MIN_VALUE) && (data_val <= MAX_VALUE));
    int pre_length = forward_length(*list);

    node_t *node = create_empty_node(data_val);
    if(list->tail != NULL)
    {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    else
    {
        list->head= node;
        list->tail= node;
    }

    assert(forward_length(*list) == pre_length + 1);
    assert(list->tail->data == data_val);
    check_list_structure(*list);
}

node_t *find(list_t list, int target)
{
    node_t *p = list.head;
    while ((p != NULL) && (p->data != target))
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return NULL;
    }
    return p;
}
void insert_in_order(list_t *list, int data_val)
{
    assert(list != NULL);
    assert((data_val >= MIN_VALUE) && (data_val <= MAX_VALUE));
    int pre_length = forward_length(*list);
    node_t new_node = *create_empty_node(data_val);
    if (list->head == NULL)
    {
        list->head= data_val;
        list->tail= data_val;
    }
    node_t *p = list->head;
    while(p->next != NULL && p->next != &new_node)
    {
        if (data_val <= p->next->data)
        {
            new_node.next = p->next;
            new_node.prev = p;
            p->next = &new_node;
            new_node.next->prev= &new_node;

        }
        else
        {
            p= p->next;
        }



    }

    assert(forward_length(*list) == pre_length + 1);
    check_ordered_list(*list);
}

void print_list(list_t list)
{
    node_t *p = list.head;
    if (p == NULL)
    {
        printf("The list is empty\n");
    }
    while (p != NULL)
    {
        printf("%d:\n", p->data);
        p = p->next;
    }
}

int grab_the_head(list_t *list)
{
    assert(list!=NULL);
    if (list->head == NULL)
    {
        return ERROR_VALUE;
    }
    int val = list->head->data;
    node_t *t = list->head;
    list->head = list->head->next;
    if (list->head != NULL)
    {
        list->head->prev = NULL;
    }
    free(t);
    return val;
}

int grab_the_tail(list_t *list)
{
    assert(list!=NULL);
    if (list->tail == NULL)
    {
        return ERROR_VALUE;
    }
    int val = list->tail->data;
    node_t *t = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL)
    {
        list->tail->next = NULL;
    }
    free(t);
    return val;
}


