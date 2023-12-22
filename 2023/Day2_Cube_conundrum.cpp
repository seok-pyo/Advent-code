#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main()
{
    int t = 0;
    ifstream input_file("input2.txt");
    string line;
    while (getline(input_file, line))
    {
        vector<string> gs;
        size_t startPos = line.find(": ") + 2;

        while (startPos != string::npos)
        {
            size_t endPos = line.find(": ", startPos);
            if (endPos == string::npos)
            {
                gs.push_back(line.substr(startPos));
                break;
            }
            gs.push_back(line.substr(startPos, endPos - startPos));
            startPos = endPos + 2;
        }

        bool shouldBreak = false;
        for (const string &g : gs)
        {
            map<string, int> m;
            // map<string, int> m = {{"red", 0}, {"green", 0}, {"blue", 0}};
            m["red"] = 0;
            m["green"] = 0;
            m["blue"] = 0;
            size_t pos = 0;

            while (pos < g.size())
            {
                size_t commaPos = g.find(", ", pos);
                if (commaPos == string::npos)
                {
                    break;
                }

                string e = g.substr(pos, commaPos - pos);
                size_t spacePos = e.find(' ');
                string a = e.substr(0, spacePos);
                string b = e.substr(spacePos + 1);
                m[b] = stoi(a);

                if (m["red"] > 12 || m["green"] > 13 || m["blue"] > 14)
                {
                    shouldBreak = true;
                    break;
                }

                pos = commaPos + 2;
            }
            if (shouldBreak)
            {
                break;
            }
        }
    }
    // cout << m << endl;
    return 0;
}
