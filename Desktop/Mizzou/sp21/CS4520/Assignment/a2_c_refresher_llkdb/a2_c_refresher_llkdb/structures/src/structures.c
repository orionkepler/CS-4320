#include "../include/structures.h"
#include <stdio.h>

// 0 means orange, 1 means apple

int compare_structs(sample_t* a, sample_t* b)
{
    if(a->a == b->a && a->b == b->b && a->c == b->c)
    {
        return 1;
    }
	return 0;
}

void print_alignments()
{
	printf("Alignment of int is %zu bytes\n",__alignof__(int));
	printf("Alignment of double is %zu bytes\n",__alignof__(double));
	printf("Alignment of float is %zu bytes\n",__alignof__(float));
	printf("Alignment of char is %zu bytes\n",__alignof__(char));
	printf("Alignment of long long is %zu bytes\n",__alignof__(long long));
	printf("Alignment of short is %zu bytes\n",__alignof__(short));
	printf("Alignment of structs are %zu bytes\n",__alignof__(fruit_t));
}

int sort_fruit(const fruit_t* a,int* apples,int* oranges, const size_t size)
{
    // vaild check
    if(!a || !apples || !oranges || size<=0)
    {
        return -1;
    }
    size_t i;
    for(i=0; i< size; i++)
    {
        if(a[i].type == 1)
        {
            apples[0]++;
        }
        else if(a[i].type == 0)
        {
            oranges[0]++;
        }
    }
    return size;
}

int initialize_array(fruit_t* a, int apples, int oranges)
{
    // vaild check
    if(!a || apples<0 || oranges <0)
    {
        return -1;
    }
    int size = apples+ oranges;
    for(int i=0; i<size-apples; i++)
    {
        a[i].type=0;
    }
    for(int i= size-apples; i<size; i++)
    {
        a[i].type = 1;
    }

	return 0;
}

int initialize_orange(orange_t* a)
{
    // vaild check
    if(!a)
    {
        return -1;
    }
    a->type = 0;
    a->weight = 0;
    a->peeled = 0;
    
	return 0;

}

int initialize_apple(apple_t* a)
{
    if(!a)
    {
        return -1;
    }
    a->type = 1;
    a->weight = 0;
    a->worms= 0;
	return 0;
}
