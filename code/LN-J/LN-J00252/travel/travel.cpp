#include <bits/stdc++.h>
using ll = long long;
bool chk1(char c)
{
    if (c == 'A' || c == 'B' || c == 'C') return 0;
    return 1;
}
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    std::string c1, s1, c2, s2; std::cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        std::cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            std::cout << 1;
            if (chk1(s1[2]) == chk1(s2[2])) {
                std::cout << 1;
                if ((chk1(s1[2]) == chk1(s2[2])) && (chk1(s1[2]) == 1 || (s1[2] == 'B' || s2[2] == 'B'))) std::cout << 1;
                else std::cout << "0";
            }
            else std::cout << "00";
        }
        else std::cout << "000";
    }
    else std::cout << "0000";
    std::cout << std::endl;
}