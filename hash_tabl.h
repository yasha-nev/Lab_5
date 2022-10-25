#ifndef HASH_TABL_H
#define HASH_TABL_H

#include <iostream>
#include "strfunction.h"

class HashTabl
{
public:
    HashTabl(int _m, int _d, int _c);
    ~HashTabl();
    void SetHashParametrs(int _d, int _c);
    void Resize(int _m);
    void Insert(char *key);
    void Delete(char *key);
    int Search(char *key);

    void Print();
    void Clear();
private:
    int Hash(char *key);
    void ReHash(int _m);
    int m;
    int c;
    int d;
    int size;
    char **tabl;
};

#endif // HASH_TABL_H
