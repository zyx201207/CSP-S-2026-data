#include <bits/stdc++.h>
using namespace std;
int ans[5];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        ans[0] = 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            ans[1] = 1;
            char a = s1[2], b = s2[2];
            if ((a < 'D' && b < 'D') || (a >= 'D' && b >= 'D')) {
                ans[2] = 1;
                if (a > b) swap(a, b);
                if ((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D' && b == 'F'))
                    ans[3] = 1;
                else ans[3] = 0;
            }
            else ans[2] = 0;
        }
        else ans[1] = 0;
    }

    else ans[0] = 0;
    for (int i = 0; i < 4; i++) {
        cout << ans[i];
    }
    return 0;
}
