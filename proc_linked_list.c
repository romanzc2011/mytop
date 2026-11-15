#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include "procinfo.h"
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
    memcpy(proc_node->node_uuid, 0, sizeof(proc_node->node_uuid));
}

// ---------------------------------------------------
// PROC INSERT LIST
// ---------------------------------------------------
uuid_t *proc_insert_list(
    ProcList *proc_list,
    ProcData *data
)
{
    // Allocate memory for proc node
    ProcNode *proc_node = malloc(sizeof(ProcNode));
    ProcData *proc_data = malloc(sizeof(ProcData));
    
    if (proc_node == NULL || proc_data == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }
    
    // Create a uuid for the new node
    uuid_generate(proc_node->node_uuid);

    // Determine if this is the first node
    if (proc_list->head == NULL) {
        proc_list->head = proc_node;
        proc_list->tail = proc_node;

        // tail points to a proc_node and set the next to null
        proc_list->tail->next = NULL;
        proc_node->data = data;
        return EXIT_SUCCESS;
    } else {
        proc_list->tail = proc_node;
        proc_node->next = NULL;
    }

    return EXIT_SUCCESS;
}

// ---------------------------------------------------
// SEARCH PROC DATA
// ---------------------------------------------------
void search_proc_data(ProcList *proc_list, uuid_t node_uuid)
{
    // Find the data assigned to the node uuid param
    ProcNode *current_proc_node = NULL;
    bool found_uuid = false;

    uuid_t current_uuid = {0};

    // Starting at list head
    current_proc_node = proc_list->head;
    memcpy(current_uuid, current_proc_node->node_uuid, sizeof(current_uuid));

    // Get current head data node uuid
    while (!found_uuid) {// ------// ---------------------------------------------------
// PROC NODE INIT
// ------------------------------------------------------------------------------------------------
// PROC NODE INIT
// ---------------------------------------------------
        // uuid compare rets 0 if same
        int comp_uuid_ret = uuid_compare(current_uuid, node_uuid);

        if (comp_uuid_ret == 0) {
            found_uuid = true;
            printf("FOUND THE UUID: %s\n", current_proc_node->node_uuid);
        } else {
            found_uuid = false;
            current_proc_node = current_proc_node->next;
        }
    }
}

// ---------------------------------------------------
// PRINT PROC DATA
// ---------------------------------------------------
void print_proc_data(ProcNode *proc_node)
{
    printf("-------------------------------------------------------\n");
    printf("UUID: %s\n", proc_node->node_uuid);
    printf("PROCSTR: %s\n", proc_node->data->procstr);
    printf("-------------------------------------------------------\n\n");
}

// ---------------------------------------------------
// DESTROY PROC LIST
// ---------------------------------------------------
void destroy_proc_list(ProcList *proc_list)
{
    ProcNode *new_proc_list_head = NULL;
    ProcData *proc_data = NULL;

    /* Loop thru entire proc list, starting with procstr, free procstr
        and continue free proc data then previous head after you assign new head 
    */
    while (proc_list->head != NULL) {
        new_proc_list_head = proc_list->head->next;
        
        // procstr is in data, free this first
        proc_data = proc_list->head->data;
        free(proc_data->procstr);
        free(proc_data);
        free(proc_list->head->data);
        free(proc_list->head);

        proc_list->head = new_proc_list_head;
    }
}

// ---------------------------------------------------
// GET NODE UUID
// ---------------------------------------------------
uuid_t *get_node_uuid(ProcList *proc_list)
{

}