#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2E6 + 10;
ll n, x[MAXN], t, d, f[MAXN], answer;
ll dis[MAXN];

void dfs(ll u) {
    for (int v = u + 1; v < n; v++) {
        if (x[v] > x[u] + d) return;
        if (dis[u] + 1 < dis[v]) {
            dis[v] = dis[u] + 1;
            f[v] = f[u];
            dfs(v);
        } else if (dis[u] + 1 == dis[v]) {
            f[v] += f[u];
            dfs(v);
        }
    }
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> t;
    while (t--) {
        cin >> n >> d;
        for (ll i = 0; i < n; i++) {
            cin >> x[i];
        }
        answer = 0;
        for (ll i = 0; i < n; i++) {
            memset(f, 0, sizeof(f));
            memset(dis, 127, sizeof(dis));
            dis[i] = 0;
            f[i] = 1;
            dfs(i);
            for (ll j = i + 1; j < n; j++) {
                if (f[j] == 2) {
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
    cout << flush;
    return 0;
}
