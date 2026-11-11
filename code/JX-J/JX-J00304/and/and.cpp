#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = -0x3f3f3f3f;
    for (int i = 0; i < (1 << n); i++) {
        int x = __builtin_popcount(i);
        if (x != m) {
            continue;
        }
        int res = -1;
        for (int j = i; j; j >>= 1) {
            if (j & 1) {
                if (res == -1) {
                    res = a[j];
                } else {
                    res &= a[j];
                }
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}
