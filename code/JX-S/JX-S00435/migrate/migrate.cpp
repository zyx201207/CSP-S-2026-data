#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
using pi = pair<int, int>;
const int N = 2e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, d, a[N], nxt[N], ans;
ll dp[N], cnt[N];

void work(ll t) {
    ll l = t, r = t, sumcnt = 0;
    for(int i = t; i >= 1; i--) {
        ll p = min(t, nxt[i]);
        if(p == i) {
            if(i != t) break;
            dp[i] = 0;
            cnt[i] = 1;
            l = r = t; sumcnt = 1;
            //cerr << "   DP_" << i << " = {" << dp[i] << ", " << cnt[i] << "}" << ", p = " << p << endl;
            continue;
        }
        while(r > p) {
            sumcnt -= cnt[r];
            --r;
        }
        while(l - 1 > i && dp[l - 1] == dp[p]) {
            --l;
            sumcnt += cnt[l];
        }
        dp[i] = dp[p] + 1;
        cnt[i] = sumcnt;
        if(cnt[i] == 2) ans++;
        //cerr << "   DP_" << i << " = {" << dp[i] << ", " << cnt[i] << "}" << ", p = " << p << ", l = " << l << ", r = " << r << endl;
    }
}

void solve() {
    ans = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = inf;
    for(int i = 1; i <= n; i++) {
        nxt[i] = min(n, ll(upper_bound(a + 1, a + n + 2, a[i] + d) - a - 1));
    }
    for(int t = 1; t <= n; t++) {
        work(t);
        //cerr << endl;
    }
    cout << ans << "\n";
    
}

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cid, T; cin >> cid >> T;
    while(T--) solve();
    return 0;
}