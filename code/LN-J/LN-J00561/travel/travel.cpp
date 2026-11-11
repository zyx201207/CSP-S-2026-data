#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int a[5] = {0, 0, 0, 1, 1};

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, c2, s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    if (s1[0] != s2[0] || s1[1] != s2[1]) {
        cout << "1000";
        return 0;
    }
    if (a[s1[2] - 'A'] != a[s2[2] - 'A']) {
        cout << 1100;
        return 0;
    }
    if (abs(s1[2] - s2[2]) == 2) {
        cout << 1110;
        return 0;
    }
    cout << 1111;
    return 0;
}
