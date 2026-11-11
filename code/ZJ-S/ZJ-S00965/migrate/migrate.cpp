#include "bits/stdc++.h"
#define F(i,x,y) for (int i = (x); i <= (y); ++ i)
#define D(i,x,y) for (int i = (x); i >= (y); -- i)
#define ll long long
#define ull unsigned long long
#define OPEN freopen ("migrate.in", "r", stdin); freopen ("migrate.out", "w", stdout);
#define IOS ios :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
using namespace std;
constexpr int N = 2e6 + 5;
ll f[N], g[N], x[N], preg[N];
int n;
ll d;
void Main () {
    cin >> n >> d;
    // cerr << n << ' ' << d << '\n';
    F (i, 1, n) cin >> x[i];
    ll ans = 0LL;
    F (L, 1, n) {
        int lpos = L, rpos = L;
        f[L] = 0LL, g[L] = preg[L] = 1LL;
        preg[L - 1] = 0LL;
        F (R, L + 1, n) {
            while (x[R] - x[lpos] > d) ++ lpos;
            if (lpos == R) break ;
            f[R] = f[lpos] + 1;
            rpos = max (rpos, lpos);
            while (rpos + 1 < R && f[rpos + 1] == f[lpos]) ++ rpos;
            g[R] = preg[rpos] - preg[lpos - 1];
            preg[R] = preg[R - 1] + g[R];
            ans += (g[R] == 2);
        }
        // F (R, L, n) cerr << f[R] << ' '; cerr << '\n';
        // F (R, L, n) cerr << g[R] << ' '; cerr << '\n';
    }
    cout << ans << '\n';
}
int main () {
    OPEN
    IOS
    int c, t;
    cin >> c >> t;
    while (t --> 0) Main ();
    return 0;
}