#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    bool f1 = 1;
    for (int i = 0; i < 2; i++) {
        if (s1[i] != s2[i]) {
            f1 = 0;
        }
    }
    cout << (c1 == c2 ? 1 : 0);
    cout << (c1 == c2 && f1 ? 1 : 0);
    bool f = 0;
    if (c1 == c2 && f1 && ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] <= 'F' && s2[2] >= 'D' && s2[2] <= 'F'))) {
        cout << 1;
        f = 1;
    } else {
        cout << 0;
    }
    if (f == 1) {
        if (s1[2] >= 'A' && s1[2] <= 'C') {
            if (abs(s1[2] - s2[2]) == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            cout << 1;
        }
    } else {
        cout << 0;
    }
    return 0;
}
