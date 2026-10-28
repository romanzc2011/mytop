#ifndef PROC_LINKED_LIST_H
#define PROC_LINKED_LIST_H

#include <uuid/uuid.h>

typedef struct
{
    ProcNode *data;
    ProcNode *next;
}ProcNode;

ProcNode *proc_list_init();
void proc_insert_list(ProcNode *proc_list);

#endif