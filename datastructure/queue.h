/* Copyright (C) 2024
 *
 * Author: Subeen Regmi <subeenregmi123@gmail.com>
 *
 * Implementation of a queue data structure
 */
#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#define MAX_QUEUE_COUNT 64

#include "list.h"

typedef List Queue;
typedef ListItem QueueItem;

inline void enque(Queue *queue, QueueItem *item);
QueueItem* deque(Queue *queue);

#endif // DATASTRUCTURE_QUEUE_H
