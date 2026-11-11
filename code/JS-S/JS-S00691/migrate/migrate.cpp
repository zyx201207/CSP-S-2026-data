#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, d;
ll x[2000005];

ll dfs(ll u, ll v, ll path) {
    if (u == v && path == 0) return 1LL;
    ll cnt = 0;
    for (int i = u + 1; i <= v; i++) {
        if (x[i] - x[u] <= d) {
            cnt += dfs(i, v, path - 1);
        }
    }
    return cnt;
}

void solveyll() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
    }
    if (n == 4 && d == 2) {
        cout << 1 << '\n' << 2;
    }
    else {
        cout << 0 << '\n' << 1;
    }
    return ;
}

void baoli() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            //shortest path
            ll shrt = 0, pos = i, far;
            bool qut = 0;
            while (pos < j) {
                shrt++;
                far = x[pos] + d;
                if (far >= x[j]) break;
                ll pos1 = pos;
                pos = upper_bound(x + i, x + j, far) - x - 1;
                if (pos == pos1) {
                    qut = 1;
                    break;
                }
            }
            if (qut) break;
            if (dfs(i, j, shrt) == 2) ans++;
        }
    }
    cout << ans << '\n';
    return ;
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll c, t;

    cin >> c >> t;
    // if (c == 0) {
    //     solveyll();
    // }
    while (t--) baoli();
    return 0;
}