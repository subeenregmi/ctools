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
    }
}

bool compare(Item item1, Item item2) {
    if (item1.type != item2.type) {
        return false;
    } 
    switch (item1.type) {
        case INTEGER:
            return item1.i == item2.i;
        case STRING:
            if (strcmp(item1.s, item2.s) == 0){
                return true;
            }
            return false;
        case CHAR:
            return item1.c == item2.c;
        case BOOL:
            return item1.b == item2.b;
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

/*
int main(){
    bool b = !5;
    printf("%i\n", b);
    Item i1 = {{1}, INTEGER};
    Item i2 = {{2}, INTEGER};
    Item i3 = {{1}, INTEGER};

    char str[] = "subeen";
    Item i4 = {{.s = str}, STRING};
    Item i5 = {{.s = "pop"}, STRING};
    Item i6 = {{.s = "subeen"}, STRING};

    printf("%i, %i\n", compare(i1, i2), compare(i3, i1));

    printf("%i, %i\n", compare(i4, i5), compare(i4, i6));
}
*/
