#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2)
    {
        cout << 1;
        if (s1.at(0) == s2.at(0) && s1.at(1) == s2.at(1))
        {
            cout << 1;
            if (((int)s1.at(2) <= 67) == ((int)s2.at(2) <= 67))
            {
                cout << 1;
                cout << (
                         ((int)s1.at(2) - (int)s2.at(2) == 1)
                         ||
                         ((int)s2.at(2) - (int)s1.at(2) == 1)
                         );
            }
            else
                cout << "00";
        }
        else
            cout << "000";
    }
    else
        cout << "0000";
    return 0;
}
