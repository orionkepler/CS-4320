#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/sstring.h"

bool string_valid(const char *str, const size_t length)
{
    // valid check
    if(length>0 && str)
    {
        // check if str is empty
        if(strcmp(str, "")==0)
        {
            return true;
        }

        for(int i=0; i<length; i++)
        {
            if(str[i]=='\0')
            {
                return true;
            }
        }
    }
    return false;
}

char *string_duplicate(const char *str, const size_t length)
{
    // valid check
    if(length>0 && str)
    {
        char *res = calloc(length, sizeof(char));
        // copy the content
        strcpy(res, str);
        return res;
    }
    return NULL;
}

bool string_equal(const char *str_a, const char *str_b, const size_t length)
{
    // valid check
    if(length>0 && str_a && str_b)
    {
        // compare the string
        if(!strcmp(str_a, str_b))
        {
            return true;
        }
    }
    return false;
}

int string_length(const char *str, const size_t length)
{
    // valid check
    if(length>0 && str)
    {
        int sL = (int)strlen(str);
        return sL;
    }
    // if the string is invalid
    return -1;
}

int string_tokenize(const char *str, const char *delims, const size_t str_length, char **tokens, const size_t max_token_length, const size_t requested_tokens)
{
    // valid check
    if(str_length>0 && tokens && max_token_length>0 && requested_tokens && str && delims)
    {
        int j;
        for(j=0; j < requested_tokens; j++)
        {
            if(tokens[j] == NULL)
            {
                return -1;
            }
        }
        char *token;
        char oStr[str_length];
        // convert str from const char* to char*
        strcpy(oStr, str);
            
        int i;
        token = strtok(oStr, delims);
        for(i = 0; i<requested_tokens;i++)
        {
            strcpy(tokens[i], token);
            token = strtok(NULL, delims);
        }
        // return token number
        if(i!=0)
        {
            return i;
        }
    }
    return 0;
}

bool string_to_int(const char *str, int *converted_value)
{
    // valid check
    if(converted_value && str)
    {
        if(atoi(str) == -1)
        {
            return false;
        }
        else
        {
            *converted_value = atoi(str);
            return true;
        }
    }
    return false;
}
