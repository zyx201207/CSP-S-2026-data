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

    const int mxN = 2e6 + 5;
    int c, n, d, x[mxN], dp[mxN], s[mxN], ans;
    int sum[mxN];

    void calc(int l) {
        REP(i, 0, n) dp[i] = 0x3f3f3f3f, s[i] = 0, sum[i] = 0;
        dp[l] = 0, s[l] = 1;
        sum[0] = 1;
        int nl = l;
        REP(i, l + 1, n) {
            while (x[nl] + d < x[i]) sum[dp[nl]] -= s[nl], nl++;
            if (nl == i) break;
            dp[i] = dp[nl] + 1;
            s[i] = sum[dp[nl]];
            sum[dp[i]] += s[i];
            if (s[i] == 2) ans++;
        }
    }

    void main() {
        ans = 0;
        cin >> n >> d;
        REP(i, 1, n) cin >> x[i];
        if (c == 11 || c == 12) {
            int l = x[2] - x[1];
            if (2 * d >= l) {
                int x = d / l;
                cout << max(n - x - x + 1, 0ll) << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            REP(l, 1, n) {
                calc(l);
            }
            cout << ans << '\n';
        }
    }
}

signed main() {
    freopen("migrate.in", "r", stdin) ? void() : void();
    freopen("migrate.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    cin >> Yyydrasil::c >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}