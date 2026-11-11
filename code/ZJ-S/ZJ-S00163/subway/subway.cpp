#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(auto i=(a);i<(b);i++)
#define REP(i,a,b) for(auto i=(a);i<=(b);i++)
#define DEP(i,a,b) for(auto i=(a);i>=(b);i--)
#define MIN(a,b) ((a)=min((a),(b)))
#define MAX(a,b) ((a)=max((a),(b)))
#define ADD(a,b) ((a)=((a)+(b))%mod)
#define MUL(a,b) ((a)=(1ll*(a)*(b))%mod)
#define ALL(a)   (a).begin(),(a).end()
#define SZ(a)    ((int)(a).size())
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

namespace Yyydrasil {

    const int inf = 0x3f3f3f3f3f3f3f3f;
    const int mxN = 500 + 5, mxM = 5e5 + 5;
    int c, n, m, d, q, w[mxM], k, a, tx, x, y, f[mxN][mxN];
    vector<pii> ways[mxM];

    void main() {
        cin >> c >> n >> m >> d >> q;
        REP(i, 1, n) REP(j, 1, n) f[i][j] = (i == j ? 0 : inf);
        REP(i, 1, m) cin >> w[i];
        REP(x, 1, n) {
            cin >> k;
            REP(i, 1, k) {
                cin >> a >> tx;
                for (auto p : ways[a]) {
                    int y = p.fi, ty = p.se;
                    MIN(f[x][y], tx + ty);
                    MIN(f[y][x], tx + ty);
                }
                ways[a].pb({x, tx});
            }
        }
        REP(k, 1, n) {
            REP(i, 1, n) {
                REP(j, 1, n) {
                    MIN(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }
        REP(i, 1, q) {
            cin >> x >> y;
            int ans = inf;
            for (auto wx : ways[x]) {
                for (auto wy : ways[y]) {
                    MIN(ans, w[x] + wx.se + f[wx.fi][wy.fi] + wy.se + w[y]);
                }
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    freopen("subway.in", "r", stdin) ? void() : void();
    freopen("subway.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}