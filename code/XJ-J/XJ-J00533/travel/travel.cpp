#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
signed main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    int f1 = (c1 == c2);
    int f2 = (s1[0] == s2[0] && s1[1] == s2[1]);
    int f3 = ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D'));
    int f4 = (abs(int(s1[2]) - int(s2[2])) == 1);
    cout << f1 << (f1 && f2) << (f1 && f2 && f3) << (f1 && f2 && f3 && f4);
    return 0;
}
