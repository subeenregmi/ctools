/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a generic doubly linked list.
 */
#ifndef DATASTRUCTURE_LIST_H
#define DATASTRUCTURE_LIST_H

#include "generic.h"


typedef struct ListItem {
    Item data;
    struct ListItem *left;
    struct ListItem *right;
} ListItem;

typedef struct List {
    struct ListItem *head;
    struct ListItem *tail;
    unsigned int count;
} List;

ListItem* create_LInt(int data);
ListItem* create_LString(char data[]);
ListItem* create_LChar(char data);
ListItem* create_LBool(bool data);

void print_list(List list);
void rprint_list(List list);

Item get_item(List list, int index);
int find_item(List list, Item item);

void append_item(List *list, ListItem *item);
void insert_item(List *list, ListItem* item, int index);

void deallocate(List *list);


#endif /* DATASTRUCTURE_H */
