#include <bits/stdc++.h>
using namespace std;

int n, m, a[100005], vis[100005];
int ans = 0;

void f(int tot, int cur) {
    if (cur == m) {
        ans = max(ans, tot);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            f((tot & a[i]), cur + 1);
        }
    }
}

int main() {
#ifndef LOCAL
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        vis[i] = 1;
        f(a[i], 1);
        vis[i] = 0;
    }
    cout << ans << endl;
    return 0;
}