#include "hash_tabl.h"
#include <fstream>
/*
 * Task
 * СНИЛС
 * Функция работы со строками
 * Квадратичное опробование
 *
 * Пример СНИЛСА
 * 123 - 456 - 789 - 01
*/

int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cout << "No data" << std::endl;
        return 0;
    }
    std::fstream file;
    int n;

    file.open(argv[1]);

    if (!file.is_open()){
        std::cout << "File doesn't open" << std::endl;
        return 0;
    }

    file >> n;
    if (file.fail()){
        std::cout << "Fail to read data" << std::endl;
        return 0;
    }

    HashTabl hash(n, 2, 5);

    for (int i = 0; i < n; i++){

        char s[50];
        file >> s;

        if (file.fail()){
            std::cout << "Fail to read data" << std::endl;
            return 0;
        }

        if (checkSnilsNumber(s)){
            hash.Insert(s);
        }
        else{
            std::cout << s << " is not a snils number\n" << std::endl;
        }
    }
    file.close();

    hash.Print();

    hash.SetHashParametrs(7, 2);

    hash.Delete("66144248871");
    hash.Print();

    hash.Insert("66144248871");
    hash.Insert("66144248878");
    hash.Print();

    return 0;
}
