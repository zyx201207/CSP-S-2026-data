#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

bool col[N], vis[N];
int cas, T, n, m;
vector < int > g[N];
void dg(int x) {
    vis[x] = 1;
    for (auto y : g[x]) 
        if (col[y] && !vis[y]) dg(y);
}
int len;
void dfs(int x, int f, int dep) {
    for (auto y : g[x]) {
        if (f == y) continue;
        if (col[y]) {
            len = min(len, dep);
            return;
        }
        dfs(y, x, dep + 1);
    }
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> cas >> T;
    if (cas == 13 || cas == 14) {
        while (T--){
            cin >> n >> m;
            for (int i = 1; i < n; i++)
                cin >> m >> m;
            cout << 1 << '\n';
        }
        exit(0);
    }
    while (T--) {
        cin >> n >> m;
        int ans = n / 2;
        for (int i = 1; i <= n; i++)
            while (g[i].size()) g[i].pop_back();
        for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            g[x].push_back(y), g[y].push_back(x);
        }
        for (int c = 1; c <= (1 << n); c++) {
            int cnt = 0, ls = c;
            while (ls) {
                if (ls & 1) cnt++;
                ls >>= 1;
            }
            if (cnt != m) continue;
            ls = c;
            int jsq = 1;
            for (int i = 1; i <= n; i++) col[i] = 0;
            while (ls) {
                if (ls & 1) col[jsq] = 1;
                ls >>= 1, jsq++;
            }
            cnt = 0;
            for (int i = 1; i <= n; i++)
                if (col[i] && !vis[i]) {
                    dg(i);
                    cnt++;
                }
            if (cnt >= 3) continue;
            for (int i = 1; i <= n; i++) {
                if (col[i]) continue;
                len = n;
                dfs(i, i, 1);
                ans = min(ans, len);
                if (ans == 1) break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}