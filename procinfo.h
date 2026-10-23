#ifndef PROCINFO_H
#define PROCINFO_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    char *procstr;
    int length;
    size_t capacity;
}ProcData;

int get_procinfo(char *filename, ProcData *proc_data);
static char *rammem_info(ProcData *proc_data);

#endif