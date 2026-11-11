#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 6e5 + 5;

int n, m, a[N], sum[N], ans;

int check(int x, int y) {
    return a[y] * (y - x + 1) - (sum[y] - sum[x - 1]);
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];

    for (int i = 1; i <= n; i++) {
        int L = 0, R = n + 1;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            if (check(M, i) <= m)
                R = M;
            else
                L = M;
        }

        int x = m - check(R, i);
        if (x == 0)
            ans = max(ans, i - R + 1);
        else if (i != n)
            ans = max(ans, i - R + 1);
        else if (check(n, 1) < m)
            ans = max (ans, max (x, n - x));
        else
            ans = max(ans, i - R + 1);
    }
    cout << ans << "\n";
}
