#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int c, n, m, d, q, minn = 1e9, x, y;
int w[500005], k[500005], a[500][1000], t[500][1000], vis[100];

void dfs(int pos, int e, int num, int pre){ // dangqianzainagezhantai, shangyigelaideshijihaoxian
    if (pos != x) num += t[pre][pos];
    if (pos == e){
        minn = min(minn, num);
        return;
    }
    bool f[100] = {0};
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k[i]; j++){
            if (a[i][j] == pos){
                f[i] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (!f[i]) continue;
        for (int j = 1; j <= k[i]; j++){
            int nxt = a[i][j];   // xiayicizoudaonagezhantai
            if (!vis[nxt]){
                vis[nxt] = 1;
                dfs(nxt, e, num + t[i][pos], i);
                vis[nxt] = 0;
            }
        }
    }
}

void solve(){
    memset(vis, 0, sizeof(vis));
    vis[x] = 1;
    minn = 1e9;
    dfs(x, y, w[x] + w[y], 0);
    cout << minn << '\n';
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) cin >> w[i];
    for (int i = 1; i <= n; i++){
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][a[i][j]];

    }
    while (q--){
        cin >> x >> y;
        solve();
    }
    return 0;
}
