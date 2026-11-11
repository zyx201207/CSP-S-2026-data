#include <bits/stdc++.h>
using namespace std;

int c1, c2;
string s1, s2;
string ans = "";

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) ans += "1";
    else {
        cout << "0000";
        return 0;
    }
    if (s1.substr(0, 2) == s2.substr(0, 2)) ans += "1";
    else {
        cout << "1000";
        return 0;
    }
    if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] > 'D')) ans += "1";
    else {
        cout << "1100";
        return 0;
    }
    if (s1[2] + 1 == s2[2]) {
        if (s1[2] == 'C' && s2[2] == 'D') {
            cout << "1110";
            return 0;
        }
        else ans += "1";
    } else {
        cout << "1110";
        return 0;
    }
    cout << ans;

    return 0;
}
