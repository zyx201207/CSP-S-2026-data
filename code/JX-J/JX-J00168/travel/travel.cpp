#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string s;
    getline(cin, s);

    int s1, t1, s2, t2;
    char c1, c2;
    sscanf(s.c_str(), "%d %d%c %d %d%c", &s1, &t1, &c1, &s2, &t2, &c2);

    if (s1 == s2) {
        cout << 1;
        if (t1 == t2) {
            cout << 1;
            if ((c1 <= 'C' && c2 <= 'C') || (c1 >= 'D' && c2 >= 'D')) {
                cout << 1;
                if (abs(c1 - c2) == 1) {
                    cout << 1;
                } else {
                    cout << "0";
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

    return 0;
}
