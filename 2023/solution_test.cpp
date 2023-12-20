#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    std::string line;
    ifstream inputFile("in.tex"); // "in.txt" 파일 열기

    if (!inputFile.is_open())
    {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    while (std::getline(inputFile, line))
    {
        std::cout << "입력 받은 줄: " << line << std::endl;
    }

    inputFile.close();

    return 0;
}
