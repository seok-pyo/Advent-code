#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
    // Advent of Code 세션 쿠키 설정
    std::string aoc_cookie = "session = MY_SESSION";

    int year = 2023;
    int day = 1;

    std::string download_command = // curl(ClientURL)을 사용해서 파일을 다운로드 하고 input.txt 파일로 저장하는 명령어 할당
        "curl --cookie \"" + aoc_cookie + "\" https://adventofcode.com/" + std::to_string(year) +
        "/day/" + std::to_string(day) + "/input > input.txt"; // 리디렉션 연산자('>')

    system(download_command.c_str()); // 명령어를 c 스타일의 문자열로 변환 후 실행 >> 해당 페이지의 쿠키를 가져와서 innput.txt로 저장

    std::ifstream input_file("input.txt");
    if (input_file.is_open())
    {
        std::string line;
        while (std::getline(input_file, line))
        {
            std::cout << line << std::endl;
        }
        input_file.close();
    }
    else
    {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
    }

    return 0;
}
