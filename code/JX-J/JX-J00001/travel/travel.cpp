#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int c1, c2, ans[5];
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if (a == c) {
        ans[1] = 1;
        if (b.substr(0, 2) == d.substr(0, 2)) {
            ans[2] = 1;
            c1 = (b[2] - '0') - 16;
            c2 = (d[2] - '0') - 16;
            if (c1 >= 4 && c2 >= 4)
                ans[3] = ans[4] = 1;
            if (c1 < 4 && c2 < 4) ans[3] = 1;
            if (abs(c1 - c2) == 1 && ans[3]) ans[4] = 1;
        }
    }
    for (int i = 1;i <= 4;i++) printf("%d", ans[i]);
}
