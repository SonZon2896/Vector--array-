#include <iostream>
#include <string>
#include <vector>

std::vector<int> chered(std::string s)
{
    std::vector<int> indexes(0);
    for (int i = 1; i < s.length() - 1; i++)
    {
        if (s[i-1] == s[i+1])
            indexes.push_back(i);
    }
}

int main()
{
    std::string s;
    std::cin >> s;
}