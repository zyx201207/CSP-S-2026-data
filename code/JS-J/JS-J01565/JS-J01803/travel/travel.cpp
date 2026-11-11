#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if ((c1[0] == c2[0]) && (c1[1] == c2[1]))
    {
        cout << "1";
        if ((s1[0] == s2[0]) && (s1[1] == s2[1]))
        {
            cout << "1";
            char z1 = s1[2], z2 = s2[2];
            if ((z1 <= 'C' && z2 <= 'C') || (z1 >= 'D' && z2 >= 'D'))
            {
                cout << "1";
                if ((z1 <= 'C' && z2 <= 'C') && abs(z1 - z2) == 1) cout << 1;
                else if ((z1 >= 'D' && z2 >= 'D') && abs(z1 - z2) == 3) cout << 1;
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
