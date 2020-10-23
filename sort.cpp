// externsort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

bool generate_file(int N, const char* fname) {

    std::ofstream outFile(fname);
    if (!outFile) return false;
    while (N-- > 0)
        outFile << rand() % 10000 << ' ';
    outFile.close();
    return true;
}

bool isSortedFile(const char* fname) {
    // Проверяет отсортированы числа в файле или нет.
    // Если все числа в неубывающем порядке, то результат true, иначе false 
    std::ifstream inFile("isSortedFile.txt", std::ios_base::binary);
    inFile.seekg(0, inFile.end);
    int length = inFile.tellg();
    inFile.seekg(0, inFile.beg);
    char* delStr = new char[length];
    inFile.read(delStr, length);
    int ArrayLen = 0;
    for (int i = 0; i < length; ++i)
    {
        if (delStr[i] == ' ') {
            ArrayLen++;
        }
    }
    int* Array = new int[ArrayLen];
    std::string str = "";
    int j = 0;
    for (int i = 0; i < length; ++i)
    {
        if (delStr[i] == ' ') {
            Array[j] = atoi(str.c_str());
            str = "";
            j++;
        }
        else {
            str = str+delStr[i];
        }
    }
    for (int i = 0; i < ArrayLen-1; ++i)
    {
        if (Array[i] > Array[i + 1]){
            delete[] Array;
           return false;
           }
         
    }
    delete[] Array;
    return true;
  
}

void MergeFileSorting(const char* fname) {

}


int main()
{
    char fname[] = "data.txt";
    if (!generate_file(1000, fname)) {
        std::cout << "Can not create file for test!" << std::endl;
        return 1;
    }

    MergeFileSorting(fname);

    if (isSortedFile(fname)) {
        std::cout << "File " << fname << "is sorted." << std::endl;
    }
    else {
        std::cout << "File " << fname << "is not sorted." << std::endl;
    }

    return 0;
}
