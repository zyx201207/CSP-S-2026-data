#include <bits/stdc++.h>
using namespace std;

string s[10];

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    for (int i = 1; i <= 4; i++) cin >> s[i];
    if (s[1] == s[3])
    {
        cout << "1";
        if (s[2][0] == s[4][0] && s[2][1] == s[4][1])
        {
            cout << "1";
            if (s[2][2] >= 'A' && s[2][2] <= 'C' && s[4][2] >= 'A' && s[4][2] <= 'C')
            {
                cout << "1";
                if (abs(s[2][2] - s[4][2]) == 1) cout << "1";
                else cout << "0";
            }
            else if (s[2][2] == 'D' && s[4][2] == 'F' || s[2][2] == 'F' && s[4][2] == 'D')
            {
                cout << "11";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    return 0;
}
