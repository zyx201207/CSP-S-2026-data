#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 5e5 + 5;
int n, m, hd[N], nxt[N], dl[N], ans[N], a[N];
ll f[N], df[N];
void init() {
    dl[n + 1] = n + 1;
    for (int i = n; i; i--) {
        if (hd[a[i]]) nxt[i] = hd[a[i]];
        hd[a[i]] = i;
        if (nxt[i]) dl[i] = i;
        else dl[i] = dl[i + 1];
    }
}
int main () {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init();
    for (int i = 1; i <= n; i++) {
        f[i]++;
        df[i] += f[i];
        df[dl[i]] -= f[i];
        if (dl[i] <= n) f[nxt[dl[i]]] += f[i];
    }
    for (int i = 1; i <= n; i++) {
        df[i] += df[i - 1];
        ans[a[i]] += df[i];
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}