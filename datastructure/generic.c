/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a generic item.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "generic.h"

void print_item(Item item) {
    switch (item.type) {
        case INTEGER:
            printf("%i", item.i);
            break;
            
        case STRING:
            printf("%s", item.s);
            break;

        case CHAR:
            printf("%c", item.c);
            break;

        case BOOL:
            printf("%i", item.b);
            break;

        default:
            break;
    }
}

void copy_item(Item *dest, Item *src) {
    dest->type = src->type;
    switch (src->type) {
        case INTEGER:
            dest->i = src->i;
            break;
        
        case STRING:
            strcpy(dest->s, src->s);
            break;

        case CHAR:
            dest->c = src->c;
            break;

        case BOOL:
            dest->b = src->b;
            break;

        default:
            break;
    }
}

void set_int(Item *item, int data) {
    item->type = INTEGER;
    item->i = data;
}

void set_string(Item *item, char data[]) {
    item->type = STRING;
    strcpy(item->s, data);
}

void set_char(Item *item, char data) {
    item->type = CHAR;
    item->c = data;
}

void set_bool(Item *item, bool data) {
    item->type = BOOL;
    item->b = data;
}
