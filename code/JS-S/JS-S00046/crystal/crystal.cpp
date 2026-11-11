#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
LL a[N], f[N];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    LL n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) f[i] = a[i] + f[i - 1];
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 1, r = i, mid;
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if (a[i] * mid - (f[i] - f[i - mid]) <= m) l = mid;
            else r = mid - 1;
        }
        ret = max(ret, l);
    }
    cout << ret;
    return 0;
}