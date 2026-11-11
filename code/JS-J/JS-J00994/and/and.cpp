#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
bool have[maxn][50], vis[maxn];
int maxtmp = 0, ans = -1;
void init(int i) {
    int x = a[i], tmp = 1;
    while (x) {
        maxtmp = max(maxtmp, tmp);
        have[i][tmp] = x % 2;
        x /= 2;
        tmp++;
    }
    return ;
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        init(i);
    }
    for (int i = maxtmp; i >= 1; i--) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (have[j][i] && !vis[j]) {
                cnt++;
                if (cnt >= m) break;
            }
        }
        if (cnt < m) continue;
        for (int j = 1; j <= n; j++) {
            if (!have[j][i]) vis[j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans == -1 && !vis[i]) {
            ans = a[i];
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) ans &= a[i];
    }
    cout << ans;
    return 0;
}
