#include "strfunction.h"
#include <iostream>

int strcmp(const char *left, const char *right){
    while (*left != '\0'){
        if (*left != *right){
            break;
        }
        left++;
        right++;
    }
    return *left - *right;
}

char *strcpy(char *in, const char *out){
    if (!in || !out){
        return nullptr;
    }
    char *ptr = in;
    while (*out != '\0'){
        *in = *out;
        in++;
        out++;
    }
    *in = '\0';
    return ptr;
}

bool checkSnilsNumber(const char *keys){
    int i = 0;
    while (*keys != '\0'){
        if (*keys > '9' || *keys < '0'){
            return false;
        }

        keys++;
        i++;
    }
    return i == 11;
}
