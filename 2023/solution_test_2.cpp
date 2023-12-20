#include <iostream>
#include <string>

int main()
{
    std::string line;
    int attempts = 3;

    while (attempts--)
    {
        std::getline(std::cin, line);
        std::cout << "입력 받은 줄: " << line << std::endl;
    }

    return 0;
}
