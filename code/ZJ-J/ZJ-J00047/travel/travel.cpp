#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//CSP-J 2026 RP+=INF

string c1, c2, s1, s2;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2) {
        cout << "0000";
    } else {
        if(s1[0] != s2[0] || s1[1] != s2[1]) {
            cout << "1000";
        } else {
            if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') {
                if(s2[2] == 'D' || s2[2] == 'F') {
                    cout << "1100";
                } else {
                    if(abs((int)s1[2] - (int)s2[2]) == 1) {
                        cout << "1111";
                    } else {
                        cout << "1110";
                    }
                }
            } else {
                if(s2[2] == 'A' || s2[2] == 'B' || s2[3] == 'C') {
                    cout << "1100";
                } else {
                    cout << "1111";
                }
            }
        }
    }
    return 0;
}
