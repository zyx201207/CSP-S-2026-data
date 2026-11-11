#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
#endif
    string c1, s1, c2, s2;
    bool flag = true;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
    } else {
        cout << 0;
        flag = false;
    }
    if (flag && s1[0] == s2[0] && s1[1] == s2[1]) {
        cout << 1;
    } else {
        cout << 0;
        flag = false;
    }
    if (flag && (s1[2] - 'A' >= 0 && s1[2] - 'A' <= 2 && s2[2] - 'A' >= 0 && s2[2] - 'A' <= 2)
        || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))) {
        cout << 1;
    } else {
        cout << 0;
        flag = false;
    }
    if (flag && ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F')
        || (s2[2] == 'A' && s1[2] == 'B') || (s2[2] == 'B' && s1[2] == 'C') || (s2[2] == 'D' && s1[2] == 'F'))) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << endl;
    return 0;
}