#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010];
int c[300010];
int ans[300010];

void solve() {
    for (int i = 1; i <= n; i++)
        ans[a[i]]++;
    for (int i = 1; i <= m; i++)
        ans[i] += ans[i - 1];
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (1ll * n * m > 100000000) {
        solve();
        return 0;
    }
    for (int i = n; i; i--) {
        if (!c[a[i]])
            c[a[i]] = i;
        for (int j = i; j <= n; j = c[a[j]] + 1)
            ans[a[j]]++;
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
