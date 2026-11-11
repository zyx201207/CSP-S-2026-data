#include <bits/stdc++.h>
using namespace std;

#define FIO "migrate"

using ll = long long;
using pii = pair <int, int>;

const int MOD = 998244353;

ll mabs(ll x){
    return x < 0? -x: x;
}

int n;
ll d, x[2000005];
int prv[2000005], nxt[2000005];
int r[2000005], l[2000005];

ll dp[2000005][3];

void solve(){
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> x[i];
        r[i] = -1e9;
        l[i] = 1e9;
    }

    int p = 0;
    for (int i = 0; i < n; i++){
        while (x[i] - x[p] > d) p++;
        prv[i] = p;
        r[prv[i]] = max(r[prv[i]], i);
        l[prv[i]] = min(l[prv[i]], i);
    }
    p = n - 1;
    for (int i = n - 1; i >= 0; i--){
        while (x[p] - x[i] > d) p--;
        nxt[i] = p;
    }

    for (int i = 0; i < n; i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;

    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (nxt[i] > i) dp[nxt[i]][0] += 1;
        if (nxt[i] > i + 1) dp[nxt[i]][1] += 1;

        if (nxt[i] > i and prv[nxt[i]] == i){
            dp[nxt[i]][0] += dp[i][0];
            dp[nxt[i]][2] += dp[i][2];
        }
        if (nxt[i] > i + 1 and prv[nxt[i] - 1] == i) dp[nxt[i]][1] += dp[i][0];
        if (nxt[i] > i and prv[nxt[i]] == i - 1) dp[nxt[i]][2] += dp[i][1];

        {
            int L = max(l[i], i + 1);
            int R = min(r[i], nxt[i]);
            if (L <= R) ans += (ll)(R - L + 1) * dp[i][2];
        }
        if (i > 0) {
            int L = max(l[i - 1], i + 1);
            int R = min(r[i - 1], nxt[i]);
            if (L <= R) ans += (ll)(R - L + 1) * dp[i][1];
        }
        // for (int j = i + 1; j <= nxt[i]; j++) if (prv[j] == i) ans += dp[i][2];
        // for (int j = i + 1; j <= nxt[i]; j++) if (prv[j] == i - 1) ans += dp[i][1];
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(FIO".in", "r", stdin);
    freopen(FIO".out", "w", stdout);

    int c, t; cin >> c >> t;
    while (t--) solve();

    return 0;
}
// chennie bless me