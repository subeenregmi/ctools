/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 * Date: 2024-01-27
 *
 * Implementation of a generic item.
 */

// #DOCSGEN-START

#ifndef DATASTRUCTURE_GENERIC_H
#define DATASTRUCTURE_GENERIC_H

#include <stdbool.h>

#define MAX_STRING_LENGTH 1024


// Enum for all types supported the 'generic' type.
typedef enum GenericTypes {
    INTEGER,
    STRING,
    CHAR,
    BOOL
} GenericTypes;

// Representation of a generic item.
typedef struct GenericItem {
    union {
        int i;
        char s[MAX_STRING_LENGTH];
        char c;
        bool b;
    };
    GenericTypes type;
} GenericItem;

void GI_print(GenericItem item);
void GI_copy(GenericItem *src, GenericItem *dest);
bool GI_compare(GenericItem item1, GenericItem item2);

void GI_set_int(GenericItem *item, int data);
void GI_set_string(GenericItem *item, char data[]);
void GI_set_char(GenericItem *item, char data);
void GI_set_bool(GenericItem *item, bool data);

GenericItem GI_create_int(int data);
GenericItem GI_create_string(char data[]);
GenericItem GI_create_char(char data);
GenericItem GI_create_bool(bool data);

#endif // DATASTRUCTURE_GENERIC_H 

// #DOCSGEN-END
