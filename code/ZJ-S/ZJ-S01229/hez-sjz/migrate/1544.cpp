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
int tid;
namespace Decimal10 {
const int N = 1e6 + 6;

namespace Solver {
int n, nxt[N], las[N];
ll d, a[N], f[N], g[N];
ll work(ll x[N], ll _d, int l, int r, ll res = 0) {
    n = r - l + 1, d = _d;
    copy(x + l, x + r + 1, a + 1);
    for (int i = 1, p = 1; i <= n; i++) {
        for (; p < n && a[p + 1] - a[i] <= d; p++);
        nxt[i] = p;
    }
    for (int i = n, p = n; i >= 1; i--) {
        for (; p > 1 && a[i] - a[p - 1] <= d; p--);
        las[i] = p;
    }

    fill(f, f + n + 1, 0);
    fill(g, g + n + 1, 0);
    L(i, 1, n) {
        f[nxt[i]]++;
        if (las[nxt[i]] == i) {
            f[nxt[i]] += f[i];
        }
    }
    R(i, n, 1) {
        g[las[i]]++;
        if (nxt[las[i]] == i) {
            g[las[i]] += g[i];
        }
    }

    L(i, 1, n) {
        int p1 = nxt[i], p2 = p1 - 1, p3 = nxt[p2];
        cerr << i << ' ' << p1 << ' ' << p2 << ' ' << p3 << '\n';
        if (p2 == i || p3 == p1) {
            continue;
        }
        if (las[p3] != p2) {
            continue;
        } // 跳这么远都有杂质, 说明寄了
        ll rgt = 0;
        // xiege baoli xian
        L(j, p1 + 1, p3) {
            rgt += las[j] == p2;
        }
        if (nxt[p1] == p3) { // p3 as end
            rgt += g[p3];
        }
        if (las[p2] != i) {
            res += rgt;
            continue;
        } // only i as begin
        res += f[i] * rgt;
    }

    return res;
}
} // namespace Solver

int n;
ll d, x[N];
void solve() {
    cin >> n >> d;
    L(i, 1, n) {
        cin >> x[i];
    }

    ll ans = 0;
    for (int l = 1, r = 1; l <= n; l = ++r) {
        for (; r < n && x[r + 1] - x[r] <= d; r++);
        ans += Solver::work(x, d, l, r);
    }

    cout << ans << '\n';
}
int main() {
    int T;
    for (qio(), cin >> tid >> T; T--; solve());
    return 0;
}

} // namespace Decimal10
bool med;

int main() {
    Decimal10::main();
    cerr << "time: " << clock() / CLOCKS_PER_SEC << "ms\n";
    cerr << "memory: " << (&med - &mbe) / 1048576.0 << "MiB\n";
    return 0;
}