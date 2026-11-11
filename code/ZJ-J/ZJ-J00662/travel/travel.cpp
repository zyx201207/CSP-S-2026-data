#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    bool flag = true;
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    // cout << "--Debug--\nc1 = " << c1 << " c2=" << c2 << "\n" << s1.substr(0, 2) << " " << s2.substr(0, 2) << " " << s1[2] << s2[2] << "\n";
    if (c1 == c2) cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if (flag && s1.substr(0, 2) == s2.substr(0, 2)) cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if (flag && (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D')) cout << 1;
    else {
        cout << 0;
        flag = 0;
    }
    if (flag && abs(s1[2] - s2[2]) == 1) cout << 1;
    else cout << 0;
    return 0;
}