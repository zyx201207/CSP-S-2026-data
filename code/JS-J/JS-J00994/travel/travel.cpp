#include <bits/stdc++.h>
using namespace std;
bool sameside(string x, string y) {
    if (x[2] == 'A' || x[2] == 'B' || x[2] == 'C') {
        return (y[2] == 'A' || y[2] == 'B' || y[2] == 'C');
    }
    else return y[2] == 'D' || y[2] == 'F';
}
bool nearto(string x, string y) {
    if (!sameside(x, y)) return false;
    if (x[2] == 'D' || x[2] == 'F') return true;
    if (x[2] == 'B' || y[2] == 'B') return true;
    return false;
}
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int sa = (s1[0] - '0') * 10 + (s1[1] - '0');
    int sb = (s2[0] - '0') * 10 + (s2[1] - '0');
    if (c1 == c2) {
        cout << "1";
        if (sa == sb) {
            cout << "1";
            if (sameside(s1, s2)) {
                cout << "1";
                if (nearto(s1, s2)) cout << "1";
                else cout << "0";
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";

    return 0;
}
