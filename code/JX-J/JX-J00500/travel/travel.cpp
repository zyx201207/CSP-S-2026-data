#include <bits/stdc++.h>
using namespace std;
bool ok[4];
bool chk(char c) {
    return c == 'A' || c == 'B' || c == 'C';
}
int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, p1, p2;
    char s1, s2;
    cin >> c1 >> p1 >> s1;
    cin >> c2 >> p2 >> s2;
    if (c1 == c2) {
        ok[0] = 1;
        if (p1 == p2) {
            ok[1] = 1;
            if (chk(s1) == chk(s2)) {
                ok[2] = 1;
                if (s1 > s2) swap(s1, s2);
                if (s1 == 'A' && s2 == 'B' || s1 == 'B' && s2 == 'C' || s1 == 'D' && s2 == 'F') {
                    ok[3] = 1;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << ok[i];
    }
    cout << endl;
    return 0;
}