#include <stdio.h>
#include <stdlib.h>
#include "proc_linked_list.h"

// ---------------------------------------------------
// PROC LIST INIT
// ---------------------------------------------------
ProcNode *proc_list_init()
{
    ProcNode *proc_list = malloc(sizeof(ProcNode));
    proc_list->data = NULL;
    proc_list->next = NULL;

    return proc_list;
}

// ---------------------------------------------------
// PROC INSERT LIST
// ---------------------------------------------------
void proc_insert_list(ProcNode *proc_list)
{

}