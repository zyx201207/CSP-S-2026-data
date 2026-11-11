#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 5e5 + 100;

LL n, m, a[MAXN], sum[MAXN], ans;

bool check(int x, int y)
{
    return a[y] * (y - x + 1) - (sum[y] - sum[x - 1]) <= m;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        LL l = 1, r = i, cur = i, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid, i)) {
                cur = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans = max(ans, i - cur + 1);
    }
    cout << ans << endl;

    return 0;
}
