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
const int N = 1e5 + 5;
const int inf = 1e9;
int n;
ll d, x[N];
pii f[N];
bool check(int s, int t) {
    L(i, s, t) {
        f[i] = pii(inf, 0);
    }
    f[s] = pii(0, 1);
    L(i, s, t) {
        if (f[i].fi >= n) {
            continue;
        }
        L(j, i + 1, t) {
            if (x[j] - x[i] > d) {
                break;
            }
            if (f[i].fi + 1 < f[j].fi) {
                f[j] = f[i];
                f[j].fi++;
            } else if (f[i].fi + 1 == f[j].fi) {
                f[j].se += f[i].se;
            }
        }
    }
    return f[t].fi <= n && f[t].se == 2;
}
int main() {
    cin >> n >> d;
    L(i, 1, n) {
        cin >> x[i];
    }
    int ans = 0;
    L(i, 1, n) {
        L(j, i + 1, n) {
            ans += check(i, j);
        }
    }
    cout << ans << '\n';
    return 0;
}
} // namespace Decimal10
bool med;

int main() {
    int c = 0, T = 0;
    cin >> c >> T;
    while (T--) Decimal10::main();
    return 0;
}