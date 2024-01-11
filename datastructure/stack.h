/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a stack.
 */
#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#define MAX_STACK_COUNT 64

#include "list.h"


typedef List Stack;
typedef ListItem StackItem;

inline void push(Stack *stack, StackItem *item);
ListItem* pop(Stack *stack);
ListItem* peek(Stack *stack);

#endif
