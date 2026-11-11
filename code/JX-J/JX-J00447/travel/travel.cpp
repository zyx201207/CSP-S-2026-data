#include <bits/stdc++.h>

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    std:: string c1, s1, c2, s2;
    std:: cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        std:: cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1])
        {
            std:: cout << 1;
            char x1 = s1[2], x2 = s2[2];
            std:: map<char, bool> mp, mp1;
            mp['A'] = 1;
            mp['B'] = 1;
            mp['C'] = 1;
            mp1['D'] = 1;
            mp1['F'] = 1;
            if ((mp[x1] && mp[x2]) || (mp1[x1] && mp1[x2]))
            {
                std:: cout << 1;
                if ((std:: abs(x1 - x2) == 1 && (x1 != 'C' || x2 != 'D')) || (x1 == 'D' && x2 == 'F') || (x1 == 'F' && x2 == 'D'))
                {
                    std:: cout << 1;
                }
                else std:: cout << "0";
            }
            else std:: cout << "00";
        }
        else std:: cout << "000";
    }
    else std:: cout << "0000";
    return 0;
}
