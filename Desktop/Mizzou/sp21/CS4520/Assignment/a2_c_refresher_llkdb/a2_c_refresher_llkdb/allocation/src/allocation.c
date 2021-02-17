#include "../include/allocation.h"
#include <stdlib.h>
#include <stdio.h>


void* allocate_array(size_t member_size, size_t nmember,bool clear)
{
    // vaild check
    if(member_size && nmember)
    {
        if(clear)
        {
            return calloc(nmember,member_size);
        }
        return malloc(member_size*nmember);
    }
    
    return NULL;
}

void* reallocate_array(void* ptr, size_t size)
{
    // vaild check
    if(ptr)
    {
        return realloc(ptr, size);
    }
    
    return NULL;
}

void deallocate_array(void** ptr)
{
    // vaild check
    if(*ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
    return;
}

char* read_line_to_buffer(char* filename)
{
    // vaild check
    if(filename)
    {
        FILE *fp = fopen(filename, "r");
        if(!fp)
        {
            return NULL;
        }
        
        char *buffer = malloc(sizeof(char)*BUFSIZ);
        if(!buffer)
        {
            fclose(fp);
            return  NULL;
        }
        
        fgets(buffer, BUFSIZ, fp);
        fclose(fp);
        return buffer;
    }
    return NULL;

}
