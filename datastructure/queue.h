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

inline void add_item(Queue *queue, QueueItem *item);
QueueItem* remove_item(Queue *queue);

#endif
