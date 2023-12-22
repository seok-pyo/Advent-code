#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    int ln, rn, i, j, sum = 0, t1, t2, cnt = 0;
    ifstream input_file("input.txt");
    // vector<string> output;

    string patterns[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string line;
    while (getline(input_file, line))
    {
        vector<int> result;
        size_t pos = 0;
        while (pos < line.length())
        {
            bool found = false;
            // while (pos < line.length() && !isdigit(line[pos]))
            // {
            //     pos++;
            // }
            // if (pos < line.length())
            //{
            for (i = 0; i < 9; i++)
            {
                if (line.find(patterns[i], pos) == pos)
                {
                    result.push_back(i + 1);
                    // pos += patterns[i].length();
                    // found = true;
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
        // }
        //}
    }

    // for (int num : result)
    // {
    //     cout << num << " ";
    // }

    cout << sum << '\n';

    return 0;
}

// string numbers[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

// string line;
// while (getline(input_file, line))
// {
//     for (i = 0; i < 9; i++)
//     {
//         size_t found = line.find(patterns[i]);
//         if (found != string::npos)
//         {
//             line.replace(found, patterns[i].length(), numbers[i]);
//             break;
//         }
//         // while (found != string::npos)
//         // {
//         //     line.replace(found, patterns[i].length(), numbers[i]);
//         //     found = line.find(patterns[i], found + 1);
//         // }
//     }

//     for (i = 0; i < 9; i++)
//     {
//         size_t found = line.rfind(patterns[i]);
//         if (found != string::npos)
//         {
//             line.replace(found, patterns[i].length(), numbers[i]);
//             break;
//         }
//     }
//     // output.push_back(line);
//     for (j = 0; line[j] != '\0'; j++)
//     {
//         if (48 <= line[j] && line[j] <= 57)
//         {
//             ln = line[j] - '0';
//             break;
//         }
//     }
//     for (j = line.length() - 1; j >= 0; j--)
//     {
//         if (48 <= line[j] && line[j] <= 57)
//         {
//             rn = line[j] - '0';
//             break;
//         }
//     }
//     if (ln == rn)
//     {
//         t1 = ln * 10 + ln;
//         sum += t1;
//     }
//     else
//     {
//         t2 = ln * 10 + rn;
//         sum += ln * 10 + rn;
//     }
//     // cnt++;
//     // printf("%d %d\n", cnt, t2);
// }
