#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 5;
int c, t, n, d, mi, tssj;
int a[N], mp[N], vis[N];
vector <int> g[N];
void dfs(int x, int fa, int step, int y){
    //cout << x << '\n';
    if(x == y){
            //cout << step << ' \n';
        mp[step]++;
        mi = min(mi, step);
        return ;
    }
    for(int v: g[x]){
        if(v == fa)
            continue;
        if(v > y)
            continue;
        if(vis[x]==1)
            continue;
        if(v == 0)
            continue;
        vis[x] = 1;
        dfs(v, x, step+1, y);
        vis[x] = 0;
    }
}
bool check(int x, int y){
    mi = 1e18;
    for(int i = 1;i <= n; i++)
        mp[i] = 0;
    for(int i = 1;i <= n; i++)
        vis[i] = 1;
    dfs(x, -1, 0, y);
    if(mp[mi] == 2)
        return 1;
    else
        return 0;
}
void solve(){
    int n, d;
    cin >> n >> d;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1;i <= n; i++){
        for(int j = i + 1;j <= n; j++){
            if(i != j && a[j] - a[i] <= d)
                g[i].push_back(j);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n; i++){
        for(int j = i+1;j <= n; j++){
            if(check(i, j))
                ans++;
        }
    }
    cout << ans << '\n';
}
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        solve();
    }
    return 0;
}
