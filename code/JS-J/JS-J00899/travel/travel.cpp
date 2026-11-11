#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
    {
        cout << "0000";
        return 0;
    }
    int a = (s1[0] - '0') * 10 + (s1[1] - '0'), b = (s2[0] - '0') * 10 + (s2[1] - '0');
    if (a != b)
    {
        cout << "1000";
        return 0;
    }
    a = s1[2] - 'A', b = s2[2] - 'A';
    if ((a < 3 && b > 2) || (a > 2 && b < 3)) cout << "1100";
    else if (abs(a - b) != 1) cout << "1110";
    else cout << "1111";
    return 0;
}
