#ifndef PROC_LINKED_LIST_H
#define PROC_LINKED_LIST_H

#include <uuid/uuid.h>

// --------------------------------------------------
// PROC NODE STRUCT
// --------------------------------------------------
typedef struct ProcNode
{
    ProcData *data;
    uuid_t node_uuid;
    struct ProcNode *next;
} ProcNode;

// --------------------------------------------------
// PROC LIST STRUCT 
// Holds meta data for the ProcNodes
// --------------------------------------------------
typedef struct ProcList
{
    ProcNode *head;
    ProcNode *tail;
    size_t size;
} ProcList;


// --------------------------------------------------
// SUBROUTINES
// --------------------------------------------------
ProcList *proc_list_init();
uuid_t *proc_insert_list(ProcList *proc_list, ProcData *data);
void search_proc_data(ProcList *proc_list, uuid_t node_uuid);
void print_proc_data(ProcNode *proc_node);
void destroy_proc_list(ProcList *proc_list);

#endif