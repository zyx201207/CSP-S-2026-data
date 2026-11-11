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

    const int mxN = 5e5 + 5;
    int n, m, a[mxN], sum[mxN];

    bool check(int x) {
        bool res = false;
        REP(i, x, n) res |= ((a[i] * x - (sum[i] - sum[i - x])) <= m);
        return res;
    }

    void main() {
        cin >> n >> m;
        REP(i, 1, n) cin >> a[i];
        sort(a + 1, a + 1 + n);
        REP(i, 1, n) sum[i] = sum[i - 1] + a[i];
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) l = mid + 1;
            else            r = mid - 1;
        }
        cout << l - 1 << '\n';
    }
}

signed main() {
    freopen("crystal.in", "r", stdin) ? void() : void();
    freopen("crystal.out", "w", stdout) ? void() : void();
    cin.tie(0) -> sync_with_stdio(false);
    int _T = 1;
    // cin >> _T;
    while (_T--) Yyydrasil::main();
    return 0;
}