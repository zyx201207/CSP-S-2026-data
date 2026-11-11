#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500, M = 5e5, D = 20, inf = 1e18;
using pii = pair <int, int>;
int c, n, m, d, q, w [M + 5], dis [N + 5] [N + 5];
vector <pii> G [M + 5], H [N + 5];
inline int mina (int &x, int y) { return x = min (x, y); }
inline int mari (int &x, int y) { return x = max (x, y); }
void Turn () {
    memset (dis, 0x3f, sizeof dis);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1 ; i <= m ; i ++) cin >> w [i];
    for (int i = 1 ; i <= n ; i ++) {
        int k; cin >> k; dis [i] [i] = 0;
        while (k --) {
            int x, w; cin >> x >> w;
            H [i]. push_back ({x, w});
            G [x]. push_back ({i, w});
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        for (auto [to, w1] : H [i])
            for (auto [j, w2] : G [to])
                mina (dis [i] [j], w1 + w2);
    for (int k = 1 ; k <= n ; k ++)
        for (int i = 1 ; i <= n ; i ++)
            for (int j = 1 ; j <= n ; j ++)
                mina (dis [i] [j], dis [i] [k] + dis [k] [j]);
    while (q --) {
        int x, y, ans = inf; cin >> x >> y;
        for (auto [i, w1] : G [x])
            for (auto [j, w2] : G [y])
                mina (ans, w1 + w2 + dis [i] [j]);
        cout << w [x] + w [y] + ans << endl;
    }
}

int _; void Init () {
    ios :: sync_with_stdio (0); cin. tie (0); cout. tie (0);
    _ = 1;
    freopen ("subway.in", "r", stdin);
    freopen ("subway.out", "w", stdout);
    // cin >> _;
}

    signed main () { Init ();
    while (_ --> 0)
    Turn (); return 0; }

// accept :: 15:14