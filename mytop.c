#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "procinfo.h"
#include "proc_linked_list.h"

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main(void)
{
    
    int proc_info_success = 0;
    int capacity = 1024;
    
    ProcList *proc_list = proc_list_init();

    ProcData *proc_data = malloc(sizeof(ProcData));
    proc_data->capacity = capacity;
    proc_data->procstr = malloc(capacity);
    proc_data->length = 0;

    proc_info_success = get_procinfo("/proc/meminfo", proc_data);

    proc_insert_list(proc_list, proc_data);

    free(proc_data->procstr);
    free(proc_data);

    return 0;
}