#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define yh(k, i, j) {ll *p = &dp[k[i].zt][k[j].zt]; (*p) = min((*p), k[i].t + k[j].t);}
ll c, n, m, d, q, w[500005], sz[500005], k[505], x1, x2, ans, x, y, dp[505][505];
struct node{
    ll t;
    int zt;
} r[500005][22];
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (ll i = 1; i <= m; i++){
        cin >> w[i];
    }
    for (ll i = 1; i <= n; i++){
        cin >> k[i];
        for (ll j = 1; j <= k[i]; j++){
            cin >> x1 >> x2;
            sz[x1]++;
            r[x1][sz[x1]] = {x2, i};
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    for (ll i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for (ll i = 1; i <= m; i++){
        node *pk = &r[i][0];
        for (ll j = 1; j <= sz[i]; j++){
            for (ll k = j + 1; k <= sz[i];){
                yh(pk, j, k);k++;
                yh(pk, j, k);k++;
            }
        }
    }
    for (ll i = 1; i <= n; i++){
        for (ll j = 1; j <= n; j++){
            dp[i][j] = min(dp[i][j], dp[j][i]);
        }
    }
    for (ll k = 1; k <= n; k++){
        for (ll i = 1; i <= n; i++){
            for (ll j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (ll i = 1; i <= q; i++){
        cin >> x >> y;
        ans = 1e18;
        for (ll j = 1; j <= sz[x]; j++){
            for (ll k = 1; k <= sz[y]; k++){
                ans = min(ans, dp[r[x][j].zt][r[y][k].zt] + r[y][k].t + r[x][j].t);
            }
        }
        cout << ans + w[x] + w[y] << endl;
    }
    return 0;
}
