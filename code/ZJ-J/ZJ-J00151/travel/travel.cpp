#include <bits/stdc++.h>

using namespace std;

string c1, s1, c2, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> c1 >> s1 >> c2 >> s2;

    cout << (c1 == c2);
    if (c1 != c2) {
        cout << "000";
        return 0;
    }

    if (s1[0] + s1[1] == s2[0] + s2[1]) {
        cout << "1";

        bool b1 = s1[2] <= 'C';
        bool b2 = s2[2] <= 'C';
        if (b1 == b2) {
            cout << "1";
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
}
