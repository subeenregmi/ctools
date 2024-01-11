/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a queue data structure
 */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

inline void enque(Queue *queue, QueueItem *item) {
    if (queue->count >= MAX_QUEUE_COUNT) {
        perror("Queue is full...");
        exit(1);
    }
    append_item(queue, item);
}

QueueItem* deque(Queue *queue) {
    if (queue->head == NULL) {
        perror("Queue is empty...");
        exit(1);
    }
    QueueItem *item = queue->head;
    queue->head = queue->head->right;
    queue->count--;
    return item;
}
