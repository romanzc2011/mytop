#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procinfo.h"
// ---------------------------------------------------------
// FUNCTIONS
// ---------------------------------------------------------
int get_procinfo(char *filename, ProcData *proc_data)
{
    int capacity = proc_data->capacity;
    int ret = 0;
    bool strfound = false;
    FILE *fp = NULL;
    char *buffer = malloc(capacity);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error reading file\n");
        free(buffer);
        return 1;
    }

    proc_data->procstr[0] = '\0';
    proc_data->length = 0;

    while (fgets(buffer, capacity, fp) != NULL) {
        if (strncmp(buffer, "Mem", 3) == 0) {
            ret = snprintf(proc_data->procstr, capacity, "%s", buffer);
            if (ret > 0) {
                printf("%s", proc_data->procstr);
            }
        }
    }

    free(buffer);
    fclose(fp);

    return 0;
}

static char *rammem_info(ProcData *proc_data)
{
    char *findstr = "Mem";
    char *needle = strstr(proc_data->procstr, findstr);

    if (needle) {
        printf("FOUND: %s\n", needle);
        return needle;
    } 
}