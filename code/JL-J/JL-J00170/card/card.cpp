#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], idx[M], ans[M], cnt[M]; bool flag[M];

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], idx[a[i]] = i;
    for (int i = 1; i <= m; i++)
        ans[i] = idx[i];
    for (int i = 1; i <= n; i++)
        if (i != idx[a[i]])
            for (int j = 1; j <= m; j++)
                if (i < idx[j] && idx[j] < idx[a[i]]) {
                    //cout << i << ' ' << j << ' ' << i - cnt[j] << '\n';
                    ans[j]--, cnt[j] += i - cnt[j];
                }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}