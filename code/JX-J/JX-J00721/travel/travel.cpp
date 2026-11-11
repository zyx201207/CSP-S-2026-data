#include<bits/stdc++.h>

using namespace std;

string a, x, b, y, ans = "0000";

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> x >> b >> y;
    if (a == b) {
        ans[0] = '1';
        if (x[0] == y[0] && x[1] == y[1]) {
            ans[1] = '1';
            if (x[2] < 'D' && y[2] < 'D') {
                ans[2] = '1';
                if (abs(x[2] - y[2]) == 1) ans[3] = '1';
            } else if (x[2] > 'C' && y[2] > 'C') {
                ans[2] = '1', ans[3] = '1';
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
