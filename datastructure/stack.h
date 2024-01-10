/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a stack.
 */
#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "list.h"

typedef List Stack;
typedef ListItem StackItem;

#define push(stack, item) append_item(stack, item)

ListItem* pop(Stack *stack);
ListItem* peek(Stack *stack);

#endif
