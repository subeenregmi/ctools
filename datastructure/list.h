/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Generic singly and doubly linked list.
 */
#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include "generic.h"

typedef struct ListItem {
    Item data;
    struct ListItem *next;
} ListItem;

typedef struct List {
    ListItem *start;
    unsigned int count;
} List;

void print_list(List list);
void deallocate(List *list);

Item get_item(List list, int index);
void add_item(List *list, ListItem *item);
void add_int(List *list, int data);
void add_string(List *list, char data[]);
void add_char(List *list, char data);
void add_bool(List *list, bool data);

#endif /* DATASTRUCTURE_H */
