/* Copyright (C) 2024 
 * 
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Generic singly and doubly linked list.
 */
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

ListItem* create_LInt(int data) {
    ListItem *new_item= malloc(sizeof(ListItem));
    set_int(&(new_item->data), data);
    return new_item;
}

ListItem* create_LString(char data[]) {
    ListItem *new_item = malloc(sizeof(ListItem));
    set_string(&(new_item->data), data);
    return new_item;
}

ListItem* create_LChar(char data) {
    ListItem *new_item = malloc(sizeof(ListItem));
    set_char(&(new_item->data), data);
    return new_item;
}

ListItem* create_LBool(bool data) {
    ListItem *new_item = malloc(sizeof(ListItem));
    set_bool(&(new_item->data), data);
    return new_item;
}

void print_list(List list) {
    ListItem *current = list.head;
    while (current != NULL) {
        print_item(current->data);
        printf("->");
        current = current->right;
    }
    printf("END\n");
}

void rprint_list(List list) {
    ListItem *current = list.tail;
    while (current != NULL) {
        print_item(current->data);
        printf("->");
        current = current->left;
    }
    printf("END\n");
}

Item get_item(List list, int index) {
    if (list.count < index){
        perror("Index is out of bounds");
        exit(1);
    }
    ListItem *current = list.head;
    for (int i=0; i<index; i++){
        current = current->right;
    }
    return current->data;
}

int find_item(List list, Item item) {
    ListItem *current = list.head;
    int index = 0;
    while (current != NULL){
        if (compare(current->data, item)) {
            return index;
        }
        index++;
        current = current->right;
    }
    perror("Item not found");
    return -1;
}

void append_item(List *list, ListItem *item) {
    if (list->head == NULL) {
        list->count = 1;
        list->head = item;
        list->tail = item;
    }
    else {
        ListItem *current = list->head;
        while (1) {
            if (current->right == NULL) {
                current->right = item;
                item->left = current;
                list->tail = item;
                list->count++;
                break;
            }
            else {
                current = current->right;
            }
        }
    }
}

void insert_item(List* list, ListItem* item, int index) {
    if (index > list->count){
        perror("Index too high");
        exit(1);
    }
    if (index == list->count){
        append_item(list, item);
    }
    else {
        ListItem *current = list->head;
        for(int i=0; i<index; i++) {
            current = current->right;
        }
        item->left = current->left;
        item->right = current;
        if (index == 0) {
            list->head = item;
        }
        else {
            current->left->right = item;
        }
        current->left = item;
        list->count++;
    }
}

ListItem* remove_item(List *list, int index) {
    if (index >= list->count || index < 0) {
        perror("Index is invalid...");
        exit(1);
    }
    ListItem *current = list->head;
    for(int i=0; i<index; i++) {
        current = current->right;
    }

    if (index == 0) {
        list->head = current->right;
        if (list->head != NULL) {
            list->head->left = NULL;
        }
        else {
            list->tail = NULL;
        }
        list->count--;
        return current;
    }
    if (index == list->count-1) {
        current->left->right = NULL;
        list->tail = current->left;
        list->count--;
        return current;
    }
    
    current->left->right = current->right;
    current->right->left = current->left;
    list->count--;
    return current;
}

void deallocate(List *list) {
    if (list->head == NULL){
        perror("Empty list...deallocate");
        exit(1);
    }
    ListItem *current = list->head;
    while (current != NULL){
        ListItem *next_item = current->right;
        printf("Freeing...");
        print_item(current->data);
        free(current);
        current = next_item;
    }
    list->count = 0;
}

int main() {
    List my_list = {NULL, NULL, 0};
    append_item(&my_list, create_LInt(5));
    append_item(&my_list, create_LInt(6));
    append_item(&my_list, create_LInt(7));
    print_list(my_list);
    remove_item(&my_list, 0);
    remove_item(&my_list, 0);
    print_list(my_list);
    remove_item(&my_list, 0);
    print_list(my_list);
    rprint_list(my_list);
}
