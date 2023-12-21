#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    int ln, rn, i, j, sum = 0, t1, t2, cnt = 0;
    std::ifstream input_file("input.txt");
    std::vector<std::string> output;

    std::string patterns[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string numbers[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

    std::string line;
    while (std::getline(input_file, line))
    {
        for (i = 0; i < 9; i++)
        {
            size_t found = line.find(patterns[i]);
            while (found != std::string::npos)
            {
                line.replace(found, patterns[i].length(), numbers[i]);
                found = line.find(patterns[i], found + 1);
            }
        }
        // output.push_back(line);
        for (j = 0; line[j] != '\0'; j++)
        {
            if (48 <= line[j] && line[j] <= 57)
            {
                ln = line[j] - '0';
                break;
            }
        }
        for (j = line.length() - 1; j >= 0; j--)
        {
            if (48 <= line[j] && line[j] <= 57)
            {
                rn = line[j] - '0';
                break;
            }
        }
        if (ln == rn)
        {
            t1 = ln * 10 + ln;
            sum += t1;
        }
        else
        {
            t2 = ln * 10 + rn;
            sum += ln * 10 + rn;
        }
        cnt++;
        printf("%d %d\n", cnt, t2);
    }

    std::cout << sum << '\n';

    return 0;
}
