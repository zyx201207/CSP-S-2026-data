#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define int long long

template<class T> inline void ckmin(T& x, T y) { if(x > y) x = y; }
template<class T> inline void ckmax(T& x, T y) { if(x < y) x = y; }
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
static constexpr int N = 2e6 + 5;
int c, n, d;
int a[N], b[N], f[N], g[N];
/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/

int l, r, st[N];
int sum[N];

void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++)cin >> a[i];
    for(int i = 1; i <= n; i++) {
        b[i] = i;
        for(int j = i; j >= 1; j--)
            if(abs(a[i] - a[j]) <= d)
                b[i] = j;
    }
    int ans = 0;
    for(int j = 0; j <= n; j++) sum[j] = 0;
    for(int i = 1; i <= n; i++) {
        f[i] = 0, g[i] = 1;
        st[l = r = 1] = i, sum[0] = 1;
        int last = 0;
        for(int j = i + 1; j <= n; j++) {
            f[j] = 0x3f3f3f3f, g[j] = 0;
            while(l <= r && st[l] < b[j]) l++;
            for(int k = max(i, b[j - 1]); k < b[j]; k++) sum[f[k]] -= g[k];

            last = j;
            if(l > r) break;

            f[j] = f[st[l]] + 1, g[j] = sum[f[st[l]]];

            while(l <= r && f[st[r]] > f[j]) r--;
            st[++r] = j, sum[f[j]] += g[j];
            ans += g[j] == 2;
        }
        for(int j = max(i, b[last]); j <= last; j++) if(f[j] <= n) sum[f[j]] = 0;
    }
    cout << ans << '\n';
}

/*~~~~~~~~~~~~~~~~~~~~ Boundary Line ~~~~~~~~~~~~~~~~~~~~*/
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int T; cin >> c >> T;
    while(T --> 0) solve();
    return 0;
}