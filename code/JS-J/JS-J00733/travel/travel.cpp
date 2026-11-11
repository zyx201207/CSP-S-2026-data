#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool f = true;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;

    if(c1 == c2 && f) cout << 1;
    else
    {
        cout << 0;
        f = 0;
    }
    if((s1[0] == s2[0] && s1[1] == s2[1]) && f) cout << 1;
    else
    {
        cout << 0;
        f = 0;
    }
    bool a = ('A' <= s1[2] && s1[2] <= 'C'), b = ('A' <= s2[2] && s2[2] <= 'C');
    if(a == b && f) cout << 1;
    else
    {
        cout << 0;
        f = 0;
    }
    if(abs(s1[2] - s2[2]) <= 1 && f) cout << 1;
    else cout << 0;
    return 0;
}
