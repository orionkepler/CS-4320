#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../include/sys_prog.h"

// LOOK INTO OPEN, READ, WRITE, CLOSE, FSTAT/STAT, LSEEK
// GOOGLE FOR ENDIANESS HELP

bool bulk_read(const char *input_filename, void *dst, const size_t offset, const size_t dst_size)
{
    // vaild check
    if(offset >= 0 && offset <= dst_size && dst_size > 0 && input_filename && dst)
    {
        // opening the file
        int fd = open(input_filename,O_RDONLY);
        
        // file check
        if(fd < 0)
        {
            return false;
        }
            
        // moving file pointer
        if(lseek(fd,offset,SEEK_SET) < 0)
        {
            return false;
        }
        // reading the file
        if(read(fd, dst, dst_size) < 0)
        {
            return false;
        }
        // closing the file
        if(close(fd) < 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool bulk_write(const void *src, const char *output_filename, const size_t offset, const size_t src_size)
{
    // vaild check
    if(offset >= 0 && src_size > 0 && src && output_filename)
    {
        int fd = open(output_filename,O_WRONLY);
        
        // file check
        if(fd < 0)
        {
            return false;
        }
        
        // moving file
        if(lseek(fd,offset,SEEK_SET) < 0)
        {
            return false;
        }
        
        // writting file
        if(write(fd, src, src_size) < 0)
        {
            return false;
        }
        
        // closing file
        if(close(fd) < 0)
        {
            return false;
        }
        
        return true;
    }
    
    return false;
}


bool file_stat(const char *query_filename, struct stat *metadata)
{
    // vaild check
    if(query_filename && metadata)
    {
        if(stat(query_filename, metadata) < 0)
        {
            return false;
        }
        return true;
    }
    return false;
}

bool endianess_converter(uint32_t *src_data, uint32_t *dst_data, const size_t src_count)
{
    // vaild check
    if(src_count > 0 && src_data && dst_data)
    {
        int i;
        for(i = 0; i < src_count; i++)
        {
            uint32_t src_elem;
            src_elem = src_data[i];
            uint8_t b[4];
            uint32_t res = 0;
            b[0] = (uint8_t) (src_elem >>0);
            b[1] = (uint8_t) (src_elem >>8);
            b[2] = (uint8_t) (src_elem >>16);
            b[3] = (uint8_t) (src_elem >>24);
            res = b[0] | b[1] | b[2] | b[3];
            dst_data[i] =res;
        }
        return true;
    }
    return false;
}

