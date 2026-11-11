#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

const int N = 5e5 + 20000;

LL a[N];
LL sum[N];

bool check(int st, int p, LL m) {
    return 1LL * (p - st + 1) * a[p] - (sum[p] - sum[st - 1]) <= m;
}

signed main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    LL m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int L = 1, R = n - i + 2;
        while (L < R - 1) {
            int mid = (L + R) / 2;
            if (check(i, i + mid - 1, m)) {
                L = mid;
            } else {
                R = mid;
            }
        }
        ans = max(ans, L);
    }
    cout << ans << endl;
    return 0;
}