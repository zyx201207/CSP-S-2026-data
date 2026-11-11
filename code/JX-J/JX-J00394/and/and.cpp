#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
int a[N], b[N];
int main () {
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long res = 0;
    for (int i = 30; i >= 0; i--) {
        int len = 0, val = 1 << i;
        for (int j = 1; j <= n; j++) {
            if ((a[j] & val)) {
                b[++ len] = a[j];
            }
        }
        if (len >= m) {
            res += 1ll * val;
            for (int j = 1; j <= len; j++) a[j] = b[j];
            n = len;
        }
    }
    cout << res << "\n";
    return 0;
}
