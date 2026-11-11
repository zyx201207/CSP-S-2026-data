#include <bits/stdc++.h>
using namespace std;

long long a[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, res = 0;
    long long m, s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int j = 0;
    for (int i = 1; i <= n; i ++) {
        while (j <= n && a[j] * (j - i + 1) - s <= m) {
            s += a[++ j];
        }
        res = max(res, j - i);
        s -= a[i];
    }
    cout << res << '\n';
    return 0;
}