#include <bits/stdc++.h>

using namespace std;

#define int long long

int c, t;
int n, d;
int e;
int ans;
int a[2001000];
int maxx = 0x3f3f3f3f;
bool f[2001000];

vector <int> g[2001000];

void dfs (int x, int y) {
    if (x > e) {
        return;
    }
    if (y > maxx) {
        return;
    }
    if (x == e) {
        if (y == maxx) {
            ans++;
        }
        else {
            maxx = y;
            ans = 1;
        }
        return;
    }
    for (auto p : g[x]) {
        if (f[p] == 1) {
            continue;
        }
        f[p] = 1;
        dfs(p, y + 1);
        f[p] = 0;
    }
}

signed main () {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--) {
        int cnt = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }
        fill (a, a + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (abs(a[i] - a[j]) <= d) {
                    g[i].push_back(j);
                }
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                fill (f, f + n + 1, 0);
                e = j;
                ans = 0;
                maxx = 0x3f3f3f3f;
                dfs(i, 0);
                if (ans == 2) {
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
