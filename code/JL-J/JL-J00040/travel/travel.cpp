#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    string ans = "";
    if (s1 == s3) ans += "1";
    else ans += "0";
    if (ans == "1" && s2[0] == s4[0] && s2[1] == s4[1]) ans += "1";
    else ans += "0";
    if (ans == "11") {
        if ((s2[2] <= 'C' && s4[2] <= 'C') || (s2[2] > 'C' && s4[2] > 'C')) ans += "1";
        else ans += "0";
    } else ans += "0";
    if ((ans == "111" || ans == "110") && (abs((int)s2[2] - (int)s4[2]) == 1)) {
        if ((s2[2] == 'C' || s2[2] == 'D') && (s4[2] == 'C' || s4[2] == 'D')) ans += "0";
        else ans += "1";
    } else ans += "0";
    cout << ans << '\n';
    return 0;
}
