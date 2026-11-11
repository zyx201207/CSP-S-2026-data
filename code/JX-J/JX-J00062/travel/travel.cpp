#include <bits/stdc++.h>
#define int long long
using namespace std;

int T = 1;
string c1, s1, c2, s2;

void Solve() {
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            cout << 1;
            bool flag1 = (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C');
            bool flag2 = (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C');
            if (flag1 == flag2) {
                cout << 1;
                //cout << s1[2] << " " << s2[2] << " " << abs(s1[2] - s2[2]) << '\n';
                if (abs(s1[2] - s2[2]) == 1) {
                    cout << 1;
                } else {
                    cout << 0;
                }
            } else {
                cout << "00";
            }
        } else {
            cout << "000";
        }
    } else {
        cout << "0000";
    }

}

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (T--) {
        Solve();
    }
    return 0;
}
