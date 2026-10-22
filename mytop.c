#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char *procstr;
    int length;
    size_t capacity;
}ProcData;

int get_procinfo(char *filename, ProcData *proc_date);

// ---------------------------------------------------------
// MAIN
// ---------------------------------------------------------
int main(void)
{
    int proc_info_success = 0;
    int capacity = 1024;
    ProcData *proc_data = malloc(capacity);
    proc_data->capacity = capacity;

    proc_info_success = get_procinfo("/proc/meminfo", proc_data);

    return 0;
}

// ---------------------------------------------------------
// FUNCTIONS
// ---------------------------------------------------------
int get_procinfo(char *filename, ProcData *proc_data)
{
    int capacity = proc_data->capacity;
    int length = proc_data->length;
    FILE *fp = NULL;
    char *buffer = malloc(capacity);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error reading file\n");
        return 1;
    }
    while (fgets(buffer, capacity, fp) != NULL) {
        printf("[INFO]: %s", buffer);
    }

    free(buffer);
    fclose(fp);

    return 0;
}