#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else cout << 0;
    string pai1, pai2;
    pai1 += s1[0];
    pai1 += s1[1];
    pai2 += s2[0];
    pai2 += s2[1];
    if (pai1 == pai2) cout << 1;
    else cout << 0;
    char ce1, ce2;
    ce1 = s1[2];
    ce2 = s2[2];
    bool f = false;
    if ('A' <= ce1 && ce1 <= 'C' && 'A' <= ce2 && ce2 <= 'C' || 'D' <= ce1 && ce1 <= 'E' && 'D' <= ce2 && ce2 <= 'E')
    {
        cout << 1;
        f = true;
    }
    else
    {
        cout << 0;
    }
    if (!f || abs(ce1 - ce2) > 1) cout << 0;
    else cout << 1;
    return 0;
}
