#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5005];
int ans[5055];
int d[5055];
int p[5055];
int t;
void ss(int x) {
    fill(p + 1, p + m + 1, 0);
    t = 0;
    for (int i = x; i <= n; ++i) {
        int k = a[i];
        if (p[k] == 0) {
            d[++t] = k;
            p[k] = t;
        } else {
            int idx = p[k];
            for (int j = idx; j <= t; ++j) {
                p[d[j]] = 0;
            }
            t = idx - 1;
            d[++t] = k;
            p[k] = t;
        }
    }
    for (int i = 1; i <= t; ++i) {
        ans[d[i]]++;
    }
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (!(cin >> n >> m)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
        ss(i);
    }
    for (int v = 1; v <= m; ++v) {
        cout << ans[v];
        if (v < m) cout << " ";
    }
    cout << endl;
    return 0;
}
