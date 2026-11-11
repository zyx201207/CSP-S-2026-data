#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    char a = s1[2], b = s2[2];
    if (c1 == c2) cout << "1";
    else
    {
        cout << "0000";
        return 0;
    }
    if (s1[1] == s2[1]) cout << "1";
    else
    {
        cout << "000";
        return 0;
    }
    if (a <= 'C' && b <= 'C' || a >= 'D' && b >= 'D') cout << "1";
    else
    {
        cout << "00";
        return 0;
    }
    if (b < a) swap(a, b);
    if (a == 'A' && b == 'B' || a == 'B' && b == 'C' || a == 'D' && b == 'E') cout << "1";
    else
    {
        cout << "0";
    }
    return 0;
}
