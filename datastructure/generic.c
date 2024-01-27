/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-01-27
 *
 * Implementation of a generic item.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "generic.h"

void GI_print(GenericItem item) {
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

void GI_copy(GenericItem *src, GenericItem *dest) {
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
    }
}

bool GI_compare(GenericItem item1, GenericItem item2) {
    if (item1.type != item2.type) {
        return false;
    } 
    switch (item1.type) {
        case INTEGER:
            return item1.i == item2.i;
        case STRING:
            return !strcmp(item1.s, item2.s);
        case CHAR:
            return item1.c == item2.c;
        case BOOL:
            return item1.b == item2.b;
        default:
            return false;
    }
}

inline void GI_set_int(GenericItem *item, int data) {
    item->type = INTEGER;
    item->i = data;
}

inline void GI_set_string(GenericItem *item, char data[]) {
    item->type = STRING;
    strcpy(item->s, data);
}

inline void GI_set_char(GenericItem *item, char data) {
    item->type = CHAR;
    item->c = data;
}

inline void GI_set_bool(GenericItem *item, bool data) {
    item->type = BOOL;
    item->b = data;
}

GenericItem GI_create_int(int data) {
    GenericItem item;
    GI_set_int(&item, data);
    return item;
}

GenericItem GI_create_string(char data[]) {
    GenericItem item;
    GI_set_string(&item, data);
    return item;
}

GenericItem GI_create_char(char data) {
    GenericItem item;
    GI_set_char(&item, data);
    return item;
}

GenericItem GI_create_bool(bool data) {
    GenericItem item;
    GI_set_bool(&item, data);
    return item;
}
