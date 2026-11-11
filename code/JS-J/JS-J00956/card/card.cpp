#include <bits/stdc++.h>
using namespace std;
const int N = 500007, M = 300007;
int n, m;
int a[N], c[N];
int p[M], ans[M];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(c, 0, sizeof(c));
        memset(p, -1, sizeof(p));
        int tot = 0;
        for (int j = i; j <= n; j++) {
            if (p[a[j]] != -1) {
                for (int k = p[a[j]] + 1; k <= tot; k++) {
                    p[c[k]] = -1;
                }
            } else {
                c[++tot] = a[j];
                p[a[j]] = tot;
            }
        }
        for (int j = 1; j <= m; j++) ans[j] += (p[j] != -1);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
