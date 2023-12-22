#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    int i, sum = 0;
    ifstream input_file("input.txt");

    string patterns[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string line;
    while (getline(input_file, line))
    {
        vector<int> result;
        size_t pos = 0;
        while (pos < line.length())
        {
            for (i = 0; i < 9; i++)
            {
                if (line.find(patterns[i], pos) == pos)
                {
                    result.push_back(i + 1);
                    pos++;
                    break;
                }
            }

            if (isdigit(line[pos]))
            {
                result.push_back(line[pos] - '0');
            }

            pos++;
        }
        if (result.front() != result.back())
            sum += 10 * result.front() + result.back();
        else if (result.front() == result.back())
            sum += 10 * result[0] + result[0];
    }
    cout << sum << '\n';

    return 0;
}
