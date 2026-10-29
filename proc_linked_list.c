#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include "proc_linked_list.h"

// ---------------------------------------------------
// PROC LIST INIT
// ---------------------------------------------------
ProcList *proc_list_init()
{
    ProcList *proc_list = malloc(sizeof(ProcList));
    proc_list->head = NULL;
    proc_list->tail = NULL;
    proc_list->size = 0;

    return proc_list;
}

// ---------------------------------------------------
// PROC NODE INIT
// ---------------------------------------------------
ProcNode *proc_node_init()
{
    ProcNode *proc_node = malloc(sizeof(ProcNode));
    proc_node->data = NULL;
    proc_node->next = NULL;
    memset(proc_node->node_uuid, 0, sizeof(proc_node->node_uuid));
}

// ---------------------------------------------------
// PROC INSERT LIST
// ---------------------------------------------------
int proc_insert_list(
    ProcList *proc_list,
    void *data
)
{
    ProcNode *new_proc_node;

    new_proc_node = malloc(sizeof(ProcNode));

    if (new_proc_node == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Assign the new uuid
    uuid_generate(new_proc_node->node_uuid);
    new_proc_node->data = data;
    new_proc_node->next = NULL;

    // Perform on empty ProcList
    if (proc_list->head == NULL) {
        proc_list->head = new_proc_node;
        proc_list->tail = new_proc_node;
        proc_list->size++;
        return EXIT_SUCCESS;
    }

    if (new_proc_node->next == NULL) {
        proc_list->tail->next = new_proc_node;
    }

    return EXIT_SUCCESS;
}