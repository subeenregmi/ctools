/* Copyright (C) 2024 
 * 
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Generic singly and doubly linked list.
 */
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

void print_list(List list) {
    ListItem *current = list.start;
    while (current != NULL) {
        print_item(current->data);
        printf("->");
        current = current->next;
    }
    printf("END\n");
}

void deallocate(List *list) {
    if (list->start == NULL){
        printf("Empty list");
    }
    ListItem* current = list->start;
    while (current != NULL){
        ListItem *next_item = current->next;
        printf("Freeing...");
        print_item(current->data);
        free(current);
        current = next_item;
    }
    list->count = 0;
}

Item get_item(List list, int index) {
    if (list.count < index){
        perror("Index is out of bounds");
        exit(1);
    }
    ListItem *current = list.start;
    for (int i=0; i<index; i++){
        current = current->next;
    }
    return current->data;
}

void add_item(List *list, ListItem *item) {
    if (list->start == NULL) {
        list->start = item;
    }
    else {
        ListItem *current = list->start;
        while (1) {
            if (current->next == NULL) {
                current->next = item;
                break;
            }
            else {
                current = current->next;
            }
        }
    }
}

void add_int(List *list, int data) {
    list->count++;

    ListItem *new_item= malloc(sizeof(Item));
    set_int(&(new_item->data), data);

    add_item(list, new_item);
}

void add_string(List *list, char data[]) {
    list->count++;

    ListItem *new_item = malloc(sizeof(Item));
    set_string(&(new_item->data), data);

    add_item(list, new_item);
}

void add_char(List *list, char data) {
    list->count++;

    ListItem *new_item = malloc(sizeof(Item));
    set_char(&(new_item->data), data);

    add_item(list, new_item);
}

void add_bool(List *list, bool data) {
    list->count++;

    ListItem *new_item = malloc(sizeof(Item));
    set_char(&(new_item->data), data);

    add_item(list, new_item);
}
