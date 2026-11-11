#include <bits/stdc++.h>
using namespace std;

#define int long long

int x, y;
string s1, s2;
bool check1(string c1, string c2) {
    if (c1[2] == 'A' && c2[2] == 'B') return true;
    if (c1[2] == 'B' && c2[2] == 'C') return true;
    if (c1[2] == 'D' && c2[2] == 'F') return true;
    if (c1[2] == 'A' && c2[2] == 'C') return true;
    return false;
}
bool check2(string c1, string c2) {
    if (c1[2] == 'A' && c2[2] == 'B') return true;
    if (c1[2] == 'B' && c2[2] == 'C') return true;
    if (c1[2] == 'D' && c2[2] == 'F') return true;
    return false;
}
signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> x >> s1 >> y >> s2;
    if (x == y) {
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            if (s1[2] > s2[2]) swap(s1, s2);
            if (check1(s1, s2)) {
                if (check2(s1, s2)) {
                    cout << "1111" << "\n";
                }
                else cout << "1110" << "\n";
            }
            else {
                cout << "1100" << "\n";
            }
        }
        else {
            cout << "1000" << "\n";
        }
    }
    else {
        cout << "0000" << "\n";
    }

    return 0;
}
