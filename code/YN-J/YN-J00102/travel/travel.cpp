#include <bits/stdc++.h>
typedef long long ll;

std::string c1, s1, c2, s2;


int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        std::cout << "1";
        if (s1.substr(0, 2) == s2.substr(0, 2))
        {
            std::cout << "1";
            if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || 
                (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))
            {
                std::cout << "1";
                if (std::abs((int)s1[2] - (int)s2[2]) <= 1)
                {
                    std::cout << "1";
                }
                else
                {
                    std::cout << "0";
                }
            }
            else
            {
                std::cout << "00";
            }
        }
        else
        {
            std::cout << "000";
        }
    }
    else
    {
        std::cout << "0000";
    }
    std::cout << "\n";

    return 0;
}