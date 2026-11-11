#include <bits/stdc++.h>
#define int long long
#define Pii pair<int, int>
#define Fr first
#define Sc second
#define lowbit(x) (x & (-x))

using namespace std;

const int kMaxN = 2e6 + 5, INF = 1e18;

int a[kMaxN], n, d;

void solve6() {
    int dis[305][305], cnt[305][305];
    cin >> n >> d;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) dis[i][j] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (a[j] - a[i] <= d) dis[i][j] = dis[j][i] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (dis[i][j] == 1 || dis[i][j] == INF) continue;
            d = dis[i][j];
            for (int a = 1; a <= n; a++) for (int b = 1; b <= n; b++) cnt[a][b] = 0;
            for (int k = i + 1; k < j; k++) {
                if (dis[i][k] + dis[k][j] == d) cnt[dis[i][k]][dis[k][j]]++;
            }
            bool flag = 1; int cnt2 = 0;
            for (int k = 1; k < d; k++) {
                if (cnt[k][d - k] > 2) flag = 0;
                if (cnt[k][d - k] == 2) cnt2++;
            }
            if (cnt2 == 1 && flag) ans++;
        }
    }
    cout << ans << '\n';
}

void solve12() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int k = a[2] - a[1];
    if (d < k || k == 0) return cout << 0 << '\n', void();
    if (d / k == 1) return cout << 0 << '\n', void();
    int L = (d / k) * 2;
    
    if (n - L + 1 < 0) cout << 0 << '\n';
    else cout << n - L + 1 << '\n';
}

signed main() {
    ios:: sync_with_stdio(0), cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int T = 1, c;
    cin >> c >> T;
    for (; T; T--) {
        if (c <= 6) solve6();
        else solve12();
    }
    return 0;
}
/*
ulimit -s 1024000 && cd "/home/noilinux/HN-S01000/migrate" && g++ migrate.cpp -o migrate -Wall -O2 && ./migrate 
*/