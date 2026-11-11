#include <iostream>
#include <cstdio>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if (s1[0] != s2[0] || s1[1] != s2[1]) {
        cout << "000";
        return 0;
    }
    cout << 1;
    char x = s1[2];
    char y = s2[2];
    if ('C' >= x && 'C' < y) {
        cout << "00";
        return 0;
    }
    if ('C' < x && 'C' >= y) {
        cout << "00";
        return 0;
    }
    cout << 1;
    if (abs(x - y) == 1) cout << 1;
    else cout << 0;

    return 0;
}
