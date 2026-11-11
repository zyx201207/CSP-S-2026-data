// tuxiaolai
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 10;

int c, n, lst[N];
ll d, x[N];

namespace Solve1 {
    const int N = 5e3 + 10;
    int dis[N][N];
    ll cnt[N][N];
    void solve() {
        ll res = 0;
        memset(dis, 0x3f, sizeof dis);
        memset(cnt, 0, sizeof cnt);
        for (int i = 1; i <= n; i++) dis[i][i] = 0, cnt[i][i] = 1;
        for (int i = n; i >= 1; i--) {
            for (int j = max(i + 1, lst[i] - 2); j <= lst[i]; j++) {
                for (int k = j; k <= n; k++) {
                    const int ndis = dis[j][k] + 1;
                    const ll ncnt = cnt[j][k];
                    if (ndis < dis[i][k]) dis[i][k] = ndis, cnt[i][k] = ncnt;
                    else if (ndis == dis[i][k]) cnt[i][k] += ncnt;
                }
            }
            for (int j = i; j <= n; j++) res += (cnt[i][j] == 2);
        }
        cout << res << '\n';
    }
}

namespace Solve2 {
    void solve() {
        const ll g = x[2] - x[1];
        if (g > d || (d / g == 1)) {
            cout << 0 << '\n';
            return;
        }
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (i + ((d / g) << 1) - 1 <= n) {
                res++;
            }
        }
        cout << res << '\n';
    }
}

namespace Solve3 {
    void solve() {
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (lst[i] >= i + 2) {
                const int r = min(lst[lst[i]], lst[lst[i] - 1]), l = lst[lst[i] - 2];
                res += r - l;
            }
        }
        cout << res << '\n';
    }
}

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    for (int l = 1, r = 1; l <= n; l++) {
        while (r < n && x[r + 1] - x[l] <= d) r++;
        lst[l] = r;
    }
    if (n <= 5000) {
        Solve3::solve();
    } else if (c == 11 || c == 12) {
        Solve2::solve();
    }
}


int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> c >> T;
    while (T--) {
        solve();
    }

    return 0;
} // g++ migrate.cpp -o migrate -O2 -std=c++14 -Wall -Wextra -Wshadow -Wconversion -Wl,--stack=512000000