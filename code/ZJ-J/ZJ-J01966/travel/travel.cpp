#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
char ans[5] = "0000";
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        ans[0] = '1';
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            ans[1] = '1';
            if ((s1[2] <= 'C' && s2[2] <= 'C') ||
                (s1[2] + s2[2] == 'D' + 'F')) {
                ans[2] = '1';
                if (s1[2] + s2[2] == 'D' + 'F' || abs(s1[2] - s2[2]) == 1)
                    ans[3] = '1';
                else
                    ans[3] = '0';
            } else
                ans[2] = '0';
        } else
            ans[1] = '0';
    } else
        ans[0] = '0';
    cout << ans << '\n';
    return 0;
}