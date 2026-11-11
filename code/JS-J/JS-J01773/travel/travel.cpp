#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
bool a1, a2, a3, a4;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    a1 = a2 = a3 = a4 = 0;
    if (c1 == c2) a1 = 1;
    if (s1[0] == s2[0] && s1[1] == s2[1] && a1) a2 = 1;
    if ((s1[2] <= 'C' && s2[2] >= 'D') || (s2[2] <= 'D' && s1[2] >= 'D')) a3 = 0;
    else if (a1 && a2) a3 = 1;
    if (abs(s1[2] - s2[2]) <= 1 && a1 && a2 && a3) a4 = 1;
    cout << a1 << a2 << a3 << a4;
    return 0;
}
