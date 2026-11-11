#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define int ll

const int N = 2e6 + 5;

int c, t, n, dt[N], len, ren, dis[N], vis[N], b[N];
ll d, x[N], ans;

void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++){
        len = 1, ren = 1, dt[1] = i, dis[i] = 1, vis[1] = 1;
        for(int j = i + 1; j <= n; j++){
            while(len <= ren && x[dt[len]] + d < x[j]) vis[dis[dt[len]]] -= b[dt[len]], ++len;
            if(len > ren) break;
            dis[j] = dis[dt[len]] + 1;
            if(vis[dis[dt[len]]] == 2) ans++;
            // if(vis[dis[dt[len]]] > 2) break;
            while(len <= ren && dis[dt[ren]] > dis[j]) vis[dis[dt[ren]]] -= b[dt[ren]], --ren;
            dt[++ren] = j, vis[dis[j]] += vis[dis[dt[len]]], b[j] = vis[dis[dt[len]]];
        }
        while(len <= ren) vis[dis[dt[ren]]] = 0, --ren;
    }
    cout << ans << '\n', ans = 0;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) solve();
    return 0;
}