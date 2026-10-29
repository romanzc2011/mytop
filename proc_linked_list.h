#ifndef PROC_LINKED_LIST_H
#define PROC_LINKED_LIST_H

#include <uuid/uuid.h>

typedef struct ProcNode
{
    char *data;
    uuid_t node_uuid[37];
    ProcNode *next;
} ProcNode;

typedef struct ProcList
{
    ProcNode *head;
    ProcNode *tail;
    size_t size;
} ProcList;


ProcNode *proc_list_init();
int proc_insert_list(ProcList *proc_list, void *data);

#endif