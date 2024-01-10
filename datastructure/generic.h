/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a generic item.
 */

#ifndef DATASTRUCTURE_GENERIC_H
#define DATASTRUCTURE_GENERIC_H

#include <stdbool.h>

#define MAX_STRING_LENGTH 64

typedef enum Types {
    INTEGER,
    STRING,
    CHAR,
    BOOL
} Types;

typedef struct Item {
    union {
        int i;
        char s[MAX_STRING_LENGTH];
        char c;
        bool b;
    };
    Types type;
} Item;

void print_item(Item item);
void copy_item(Item *dest, Item *src);
bool compare(Item item1, Item item2);

void set_int(Item *item, int data);
void set_string(Item *item, char data[]);
void set_char(Item *item, char data);
void set_bool(Item *item, bool data);

#endif /* DATASTRUCTURE_GENERIC_H */
