#include "../include/bitmap.h"
#include <math.h>
// data is an array of uint8_t and needs to be allocated in bitmap_create
//      and used in the remaining bitmap functions. You will use data for any bit operations and bit logic
// bit_count the number of requested bits, set in bitmap_create from n_bits
// byte_count the total number of bytes the data contains, set in bitmap_create


bitmap_t *bitmap_create(size_t n_bits)
{
    // vaild check
    if(n_bits>0)
    {
        size_t n_bytes = ceil(n_bits/8.0);

        bitmap_t* Bitmap = malloc(sizeof(bitmap_t));
        
        Bitmap->data = calloc(n_bytes, sizeof(uint8_t));
        Bitmap->bit_count = n_bits;
        Bitmap->byte_count = n_bytes;
        
        return Bitmap;
    }
    return NULL;
}

bool bitmap_set(bitmap_t *const bitmap, const size_t bit)
{
    // vaild check
    if(bitmap && bit>=0 && bit<=bitmap->bit_count)
    {
        bitmap->data[bit/8] |= 1 << (bit%8);
        return true;
    }
    return false;
}

bool bitmap_reset(bitmap_t *const bitmap, const size_t bit)
{
    // vaild check
    if(bitmap && bit >=0 && bit<=bitmap->bit_count)
    {
        bitmap->data[bit/8] &= ~(1 << (bit%8));
        return true;
    }
    return false;
}

bool bitmap_test(const bitmap_t *const bitmap, const size_t bit)
{
    // vaild check
    if(bit >= 0 && bit<=bitmap->bit_count && bitmap)
    {
        // test bit
        if((bitmap->data[bit/8] & (1<<(bit%8))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

size_t bitmap_ffs(const bitmap_t *const bitmap)
{
    // vaild check
    if(bitmap)
    {
        int i;
        for(i = 0; i < bitmap->bit_count; i++)
        {
            if(bitmap_test(bitmap, i))
            {
                return (size_t)i;
            }
        }
    }
    return SIZE_MAX;
}

size_t bitmap_ffz(const bitmap_t *const bitmap)
{
    // vaild check
    if(bitmap)
    {
        int i;
        for(i = 0; i < bitmap->bit_count; i++)
        {
            if(!bitmap_test(bitmap, i))
            {
                return (size_t)i;
            }
        }
    }
    return SIZE_MAX;
}

bool bitmap_destroy(bitmap_t *bitmap)
{
    // vaild check
    if(bitmap)
    {
        free(bitmap);
        return true;
    }
    return false;
}
