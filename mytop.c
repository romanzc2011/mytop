#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "procinfo.h"

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main(void)
{
    
    int proc_info_success = 0;
    int capacity = 1024;
    ProcData *proc_data = malloc(sizeof(ProcData));
    proc_data->capacity = capacity;
    proc_data->procstr = malloc(capacity);
    proc_data->length = 0;

    proc_info_success = get_procinfo("/proc/meminfo", proc_data);

    free(proc_data->procstr);
    free(proc_data);

    return 0;
}