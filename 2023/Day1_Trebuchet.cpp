#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
    int ln, rn, i, sum = 0;
    std::ifstream input_file("input.txt");
    std::string line;
    while (std::getline(input_file, line))
    {
        for (i = 0; line[i] != '\0'; i++)
        {
            if (48 <= line[i] && line[i] <= 57)
            {
                ln = line[i] - '0';
                break;
            }
        }
        for (i = line.length() - 1; i >= 0; i--)
        {
            if (48 <= line[i] && line[i] <= 57)
            {
                rn = line[i] - '0';
                break;
            }
        }
        if (ln == rn)
            sum += ln * 10 + ln;
        else
            sum += ln * 10 + rn;
    }
    std::cout << sum << '\n';

    return 0;
}
