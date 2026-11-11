#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N];
int main() {
	freopen("crystal3.in", "r", stdin);
    cin >> n >> m; int ans = 0;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int t = 1;t <= n;t ++) {
        int tot = 0, mx = a[t];
        for (int i = t;i <= n;i ++) {
            if (mx < a[i]) {
               tot += (i - t) * (a[i] - mx), mx = a[i];
            } else {
                tot += mx - a[i];
            }
            if (tot <= m) ans = max(ans, i - t + 1); else break;
        }
    } cout << ans;
}