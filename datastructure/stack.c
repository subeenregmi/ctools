/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a stack.
 */
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

inline void push(Stack *stack, StackItem *item) {
    if (stack->count >= MAX_STACK_COUNT) {
        perror("Stack is full...");
        exit(1);
    }
    append_item(stack, item);
}

StackItem* pop(Stack *stack) {
    if (stack->count == 0) {
        perror("Stack is empty...");
        exit(1);
    }
    if (stack->count == 1) {
        stack->count--;
        StackItem *item = stack->tail;
        stack->head = NULL;
        stack->tail = NULL;
        return item;
    }
    stack->count--;
    StackItem *item = stack->tail;
    stack->tail = item->left;
    stack->tail->right = NULL;
    return item;
}

StackItem* peek(Stack *stack) {
    return stack->tail;
}
