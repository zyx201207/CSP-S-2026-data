#include <bits/stdc++.h>
using namespace std;
string s1, s2, c1, c2;
int a, b, c, d, e, f;

signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> s2 >> c1 >> c2;
    a = (s1[0] - 48) * 10 + s1[1] - 48;
    d = (c1[0] - 48) * 10 + c1[1] - 48;
    b = (s2[0] - 48) * 10 + s2[1] - 48;
    e = (c2[0] - 48) * 10 + c2[1] - 48;
    c = s2[2] - 64;
    f = c2[2] - 64;
    if (a == d) cout << 1;
    else
    {
        cout << "0000";
        return 0;
    }
    if (b == e)
    {
        cout << 1;
    }
    else
    {
        cout << "000";
        return 0;
    }
    if ((c <= 3 && f >= 4) || (c >= 4 && f <= 3))
    {
        cout << "00";
        return 0;
    }
    cout << 1;
    if ((c <= 3 && abs(c - f) == 1) || (c >= 4 && abs(c - f) == 2)) cout << 1;
    else cout << 0;
    return 0;
}
