#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005],ans = 0,min_dist = 1e18;
bool vis[2000005];
map <long long,long long> mp;
vector <int> g[2000005];
void dfs(int cur,int des,long long cnt){
    if (cur == des){
        min_dist = min(min_dist,cnt);
        mp[cnt]++;
        return;
    }
    for (int i = 0;i < g[cur].size();i++){
        int u = g[cur][i];
        if (!vis[u]){
            vis[u] = 1;
            dfs(u,des,cnt + 1);
            vis[u] = 0;
        }
    }
    return;
}
bool judge(int u,int v){
    min_dist = 1e18;
    memset(vis,0,sizeof(vis));
    mp.clear();
    dfs(u,v,0ll);
    if (mp[min_dist] == 2){
        return true;
    }
    return false;
}
void solve(){
    cin >> n >> d;
    for (int i = 0;i < n;i++){
        g[i].clear();
    }
    for (int i = 0;i < n;i++){
        cin >> x[i];
        for (int j = 0;j < i;j++){
            if (x[i] - x[j] < d + 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    ans = 0;
    for (int i = 0;i < n;i++){
        for (int j = i - 1;j > -1;j--){
            if (judge(j,i)){
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--){
        solve();
    }
    return 0;
}
