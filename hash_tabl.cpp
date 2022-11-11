#include "hash_tabl.h"

HashTabl::HashTabl(int _m, int _c, int _d)
{
    m    = _m;
    c    = _c;
    d    = _d;
    size = 0;

    tabl = new char * [m];
    for (int i = 0; i < m; i++){
        tabl[i] = nullptr;
    }
}
HashTabl::~HashTabl(){
    for (int i = 0; i < m; i++) {
        delete [] tabl[i];
    }
    delete [] tabl;
}
void HashTabl::Resize(int _m){
    if (_m < -1 || _m < size){
        std::cout << "\nResize to "<< _m <<" error\n";
        return;
    }
    std::cout << "\nResize to "<< _m <<" correct\n";
    ReHash(_m);
}

void HashTabl::SetHashParametrs(int _d, int _c)
{
    d = _d;
    c = _c;
    std::cout << "New hash parametrs " <<
                 "d = " << d << " " <<
                 "c = " << c << "\n";
    ReHash(m);
}

int HashTabl::Hash(char *key){
    int h = 0, a = 127;
    while (*key != '\0'){
        h = (a * h + (*key)) % m;
        key++;
    }
    return h;
}

void HashTabl::ReHash(int _m){
    char ** n_tabl = new char *[_m];
    for (int i = 0; i < _m; i++){
        n_tabl[i] = nullptr;
    }
    int past_m = m;
    char **past_tabl = tabl;

    m = _m;
    tabl = n_tabl;
    size = 0;

    for (int i = 0; i < past_m; i++){
        if (past_tabl[i]){
            Insert(past_tabl[i]);
            delete [] past_tabl[i];
        }
    }

    delete [] past_tabl;
}

void HashTabl::Insert(char *key){
    if (size == m){
        Resize(m * 2);
    }
    int a = Hash(key);
    int h = a;
    int first_i;
    int i;

    float k = (-c/ 2 / d);
    if (k < 0){
    	i = 0;
    }
    else{
    	i = k;
    }
    first_i = i;

    while (tabl[h]){
        h = (a + c * i + d * i * i) % m;
        if (i > (m - i) * (m - i)){
        	break;
        }
        i++;

    }
    if (tabl[h]){
        std::cout << "Inseart Error\n" << std::endl;
    }
    else{
        size++;
        tabl[h] = new char[11];
        strcpy(tabl[h], key);
    }
}

void HashTabl::Delete(char *key){
    int h = Search(key);
    if (h == -1){
        std::cout << "\nDelete error" << std::endl;
        return;
    }
    std::cout << "Delete key - "
              << key << "\n"
              << std::endl;
    size--;
    if (tabl[h]){
        delete[] tabl[h];
    }
    tabl[h] = nullptr;
}

void HashTabl::Print(){
    std::cout << "\n-----------PRINT------------\n";
    for (int i = 0; i < m; i++){
        if (tabl[i]){
            std::cout << tabl[i] << std::endl;
        }
        else{
            std::cout << "----" << std::endl;
        }
    }
    std::cout << "----------------------------\n\n";
}

int HashTabl::Search(char *key){
    int a = Hash(key);
    int h = a;
    int i = 0;
    while (strcmp(tabl[h], key)){
        h = a + c * i + d * i * i;
        if (h >= m){
            h = h % m;
        }
        i++;
        if (i > 2 * m){
            break;
        }

    }
    if (i > 2 * m){
        std::cout << "\nKey not find" << std::endl;
        return -1;
    }

    return h;
}

void HashTabl::Clear(){
    for (int i = 0; i < m; i++) {
        delete [] tabl[i];
        tabl[i] = nullptr;
    }
}
