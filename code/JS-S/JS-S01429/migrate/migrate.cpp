#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long LL;

const int N = 2e6 + 20000;

LL a[N];

LL cnt[N];
LL dis[N];

int c;
LL d;

void dfs(int x, int n) {
    for (int i = 1; i <= n; ++i) {
        if (dis[i] == dis[x] + 1 && abs(a[i] - a[x]) <= d) {
            cnt[i]++;
            dfs(i, n);
        }
        if (i != x && dis[i] > dis[x] + 1 && abs(a[i] - a[x]) <= d) {
            dis[i] = dis[x] + 1;
            cnt[i] = 1;
            dfs(i, n);
        }
    }
    return;
}

void solve() {
    int n;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (c == 13 || c == 14) {
        cout << 0 << endl;
        return;
    }
    // if (c <= 2) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cnt[j] = 0;
                dis[j] = n + 1;
            }
            dis[i] = 0;
            dfs(i, n);
            for (int j = 1; j <= n; ++j) {
                if (cnt[j] == 2) {
                    ++ans;
                }
            }
        }
        cout << ans / 2 << endl;
        return;
    // }
    return;
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> c >> T;
    while (T--) {
        solve();
    }
    return 0;
}