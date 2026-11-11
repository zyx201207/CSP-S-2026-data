#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N = 307;

int n, m, cnt;
int a[N];
int mk[N], nnn;
vector<int> g[N];
int vis[N][N];

void dfs(int d, int u) {
    vis[u][d]++;
    //cout << d << endl;
    if (u == nnn) {
        cnt = max(cnt, d);
        return;
    }
    for (auto v : g[u]) {
        if (u == v) continue;
        dfs(d + 1, v);
    }
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int c, T;
    cin >> c >> T;
    while (T--) {
        memset(mk, 0, sizeof(mk));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++) g[i].clear();
        int ans = 0;
        cin >> n >> m;
        int ad = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] < 0) ad = max(ad, 0 - a[i]);
        }
        for (int i = 1; i <= n; i++) {
            a[i] += ad + 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] + m >= a[j]) {
                    g[i].push_back(j);
                    mk[i] = mk[j] = 1;
                }
                else {
                    break;
                }
            }
        }
        //for (int i = 1; i <= n; i++) for (auto j : g[i]) cout << i << " " << j << endl;
        int f[N];
        for (int i = 1; i <= n; i++) {
            if (mk[i] == 1) nnn = i;
        }
        for (int k = 1; k <= n - 1; k++) {
            if (mk[k] == 0) continue;
            memset(vis, 0, sizeof(vis));
            cnt = 0;
            dfs(1, k);
            memset(f, cnt, sizeof(f));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= cnt; j++) {
                    if (vis[i][j] != 0) f[i] = min(f[i], j);
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= cnt; j++) {
                    //cout << i << " " << j <<  " " << vis[i][j] << endl;
                    if (vis[i][j] == 2 && f[i] == j) ans++;
                }
            }
        }
        cout << ans << endl;
    }






    return 0;
}

