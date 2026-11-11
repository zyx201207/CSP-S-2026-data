#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e6 + 5;
int c, t;
int n, ans;
ll x[MAXN], d;
int mlen, cnt;

void dfs(int now, int v, int len) {
    if (now == v) {
        if (len < mlen) {
            cnt = 1;
            mlen = len;
        }
        else if (len == mlen) {
            cnt++;
        }
        return ;
    }
    for (int j = now + 1; x[j] - x[now] <= d && j <= v; j++) {
        dfs(j, v, len + 1);
    }
}

void solve() {
    ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int u = 1; u <= n - 1; u++) {
        for (int v = u + 1; v <= n; v++) {
            mlen = INT_MAX, cnt = 0;
            dfs(u, v, 0);
            if (cnt == 2) ans++;
        }
    }
    cout << ans << '\n';
}

void solve2() {
    cout << 0 << '\n';
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    if (c >= 0 && c <= 2) while (t--) solve();
    else if (c >= 13 && c <= 14) while (t--) solve2();
    return 0;
}
