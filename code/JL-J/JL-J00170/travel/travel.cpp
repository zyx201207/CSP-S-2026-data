#include <bits/stdc++.h>
#define int long long
using namespace std;

string c1, c2, s1, s2;

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2)
        return cout << "0000" << '\n', 0;
    else
        cout << '1';
    if (s1[0] == s2[0] && s1[1] == s2[1])
        cout << '1';
    else
        return cout << "000" << '\n', 0;
    if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))
        cout << '1';
    else
        return cout << "00" << '\n', 0;
    if ((s1[2] == 'D' || s1[2] == 'F') || (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]))
        cout << '1';
    else
        return cout << '0' << '\n', 0;
    return 0;
}
// 18 min, /fn