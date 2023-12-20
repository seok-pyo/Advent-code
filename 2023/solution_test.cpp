#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    std::string line;             // std::string 타입으로 line 변수 선언
    ifstream inputFile("in.tex"); // "in.txt" 파일 열기

    if (!inputFile.is_open())
    {
        cerr << "파일을 열 수 없습니다." << endl;
        return 1;
    }

    while (std::getline(inputFile, line)) // std::getline() 함수로 한 줄씩 텍스트를 읽어옴
    {
        std::cout << "입력 받은 줄: " << line << std::endl; // std::end1은 개행문자
    }

    inputFile.close();

    return 0;
}
