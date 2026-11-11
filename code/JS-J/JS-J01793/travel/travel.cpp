#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
bool left(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return true;
    return false;
}
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 != c2) {
        cout << "0000";
        return 0;
    }
    string ans = "1";
    if (s1[0] == s2[0] && s1[1] == s2[1]) {
        ans += '1';
    }
    else ans += '0';
    if ((s1[0] == s2[0] && s1[1] == s2[1]) && (left(s1[2]) == left(s2[2]))) {
        ans += '1';
    }
    else ans += '0';
    if (ans[2] == '1') {
        if (abs(s1[2] - s2[2]) == 1) ans += '1';
        else ans += '0';
    }
    else ans += '0';
    cout << ans << endl;
    return 0;
}
