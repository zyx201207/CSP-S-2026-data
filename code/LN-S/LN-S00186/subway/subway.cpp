#include <bits/stdc++.h>
using namespace std;

int w[500005];
int a[505][1005], t[505][1005], mp[505][1005], zt[505][1005], wt[505][1005], cnt[505];
int vis[500005];
int dfs(int sx, int sy, int money, int ntz){
    if(sx == sy){
        return money;
    }
    for(int i = 1; i <= cnt[sx]; i++){
        if(vis[mp[sx][i]] == 1) continue;
        vis[mp[sx][i]] = 1;
        if(ntz != zt[sx][mp[sx][i]]){
            money += wt[ntz][mp[sx][i]];
            money += wt[zt[sx][mp[sx][i]]][mp[sx][i]];
        }
        dfs(mp[sx][i], sy, money, zt[sx][mp[sx][i]]);
        if(ntz != zt[sx][mp[sx][i]]){
            money -= wt[ntz][mp[sx][i]];
            money -= wt[zt[sx][mp[sx][i]]][mp[sx][i]];
        }
        money -= t[sx][i];
        vis[mp[sx][i]] = 0;
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio("false");
    cin.tie(0);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        cin >> a[i][1] >> t[i][1];
        wt[i][a[i][1]] = t[i][1];
        for(int j = 2; j <= k; j++){
            cin >> a[i][j] >> t[i][j];
            mp[a[i][j - 1]][++cnt[a[i][j - 1]]] = a[i][j];
            zt[a[i][j - 1]][a[i][j]] = i;
            mp[a[i][j]][++cnt[a[i][j]]] = a[i][j - 1];
            zt[a[i][j]][a[i][j - 1]] = i;
            wt[i][a[i][j]] = t[i][j];
        }
    }
    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        int ans = 0;
        ans += w[x];
        ans += w[y];
        ans = dfs(x, y, ans, 0);
        cout << ans << endl;
    }
    return 0;
}
