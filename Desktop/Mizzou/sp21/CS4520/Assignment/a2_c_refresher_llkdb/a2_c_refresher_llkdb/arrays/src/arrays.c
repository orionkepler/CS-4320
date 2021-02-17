#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count)
{
    // vaild check
    if(src && elem_size>0 && elem_count>0 && dst)
    {
    // copy the array
        memcpy(dst, src, elem_count*elem_size);
        return true;
    }
    return false;
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count)
{
    // vaild check
    if(elem_size>0 && elem_count>0 && data_one && data_two)
    {
        // if the result is 0
        if(!memcmp(data_one, data_two, elem_count*elem_size))
        {
            return true;
        }
    }
    return false;
}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count)
{
    // vaild check
    if(elem_size>0 && elem_count>0 && data && target)
    {
        // compare target with each element
        for(int i=0; i<elem_count; i++)
        {
            // if the result is 0
            if(!memcmp(data, target, elem_size))
            {
                return i;
            }

            // point to the next element
            data = data + elem_size;
        }
    }
    // if not found
    return -1;
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count)
{
    // valid check
    if(elem_size>0 && elem_count>0 && src_data && dst_file)
    {
        // check if the file name is good
        if(strcmp(dst_file, "\n")==0 || strcmp(dst_file, "")==0)
        {
            return false;
        }
        
        FILE *f1;
        f1 = fopen(dst_file, "wb");
        fwrite(src_data, elem_size, elem_count, f1);
        fclose(f1);
        return true;
    }
    return false;
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count)
{
    // vaild check
    if(elem_size>0 && elem_count>0 && src_file && dst_data)
    {
        // check if the file name is good
        if(strcmp(src_file, "\n")==0 || strcmp(src_file, "")==0)
        {
            return false;
        }
        
        FILE *f1;
        f1 = fopen(src_file, "rb");
        fread(dst_data, elem_size, elem_count, f1);
        fclose(f1);
        return true;
    }
    return false;
}

