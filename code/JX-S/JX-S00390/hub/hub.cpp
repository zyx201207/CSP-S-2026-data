#include <iostream>
using namespace std;

int T, n, k, x;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (cin >> T >> T; T --; ) {
        cin >> n >> k;
        for (int i = 1; i < n; i ++) cin >> x >> x;
        x = (n + 1) / 2;
        if (k == 0) { cout << (x + 1) / 2 << '\n'; continue; }
        int ans = 1e9;
        for (int l = x / 2 - 10; l <= x / 2 + 10; l ++) {
            int r = x - l - 1;
            if (l < 0 || r < 0) continue;
            int xl = l + 1, xr = r + 1;
            for (int uk = k / 2 - 10; uk <= k / 2 + 10; uk ++) {
                int dk = k - uk;
                if (uk <= 0 || dk <= 0) continue;
                if (uk > l + 1 || dk > r + 1) continue;
                ans = min(ans, max((l + 2 - uk) / 2, (r + 2 - dk) / 2));
            }
        } cout << ans << '\n';
    } return 0;
}
