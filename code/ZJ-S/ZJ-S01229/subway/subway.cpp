#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector < int >;
using pii = pair < int, int >;
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define qio() cin.tie(0) -> sync_with_stdio(0)
#define L(i, l, r) for (int i = l; i <= (int)(r); i++)
#define R(i, r, l) for (int i = r; i >= (int)(l); i--)
#define rep(i, l, r) for (int i = l; i < (int)(r); i++)
#define per(i, r, l) for (int i = r - 1; i >= (int)(l); i--)
#define FileIO(name) \
    freopen(name ".in", "r", stdin); \
    freopen(name ".out", "w", stdout)

bool mbe;
namespace Decimal10 {
const int M = 5e5 + 5, N = 505;
const ll inf = 0x3f3f3f3f'3f3f3f3f;
int tid, n, m, d, q;
ll w[M], G[N][N];
vector < pii > stas[N], line[M];
int main() {
    qio(), cin >> tid >> n >> m >> d >> q;
    L(i, 1, m) {
        cin >> w[i];
    }

    memset(G, 0x3f, sizeof G);
    L(i, 1, n) {
        G[i][i] = 0;
    }

    L(i, 1, n) {
        int k, p, t;
        for (cin >> k; k--; ) {
            cin >> p >> t;
            stas[i].pb({p, t});
            line[p].pb({i, t});
        }
    }
    
    L(i, 1, m) {
        rep(j, 0, sz(line[i])) {
            rep(k, j + 1, sz(line[i])) {
                auto [l1, t1] = line[i][j];
                auto [l2, t2] = line[i][k];
                G[l1][l2] = min < ll >(G[l1][l2], t1 + t2);
                G[l2][l1] = G[l1][l2];
            }
        }
    }

    L(k, 1, n) {
        L(i, 1, n) {
            L(j, 1, n) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    for (int x, y; q--; ) {
        cin >> x >> y;
        ll ans = inf;
        for (auto [ls, ts] : line[x]) {
            for (auto [lt, tt] : line[y]) {
                ans = min(ans, ts + tt + G[ls][lt]);
            }
        }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}
} // namespace Decimal10
bool med;

int main() {
    FileIO("subway");
    Decimal10::main();
    cerr << "time: " << clock() / CLOCKS_PER_SEC << "ms\n";
    cerr << "memory: " << (&med - &mbe) / 1048576.0 << "MiB\n";
    return 0;
}