#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,part[1000005],tot = 0;
long long ans = 1e18,min_dist = 1e18;
bool used[1000005],vis[1000005];
vector <int> g[1000005];
vector <int> v;
void dfs_dist(int cur,int des,long long cnt){
    if (cur == des){
        min_dist = min(min_dist,cnt);
        return;
    }
    for (int i = 0;i < g[cur].size();i++){
        int u = g[cur][i];
        if (!vis[u]){
            vis[u] = 1;
            dfs_dist(u,des,cnt + 1);
            vis[u] = 0;
        }
    }
    return;
}
long long dist(int u,int v){
    min_dist = 1e18;
    memset(vis,0,sizeof(vis));
    dfs_dist(u,v,0ll);
    return min_dist;
}
void dfs(int cur,int k){
    for (int i = 0;i < g[cur].size();i++){
        int u = g[cur][i];
        if (!vis[u]){
            vis[u] = 1;
            part[u] = k;
            dfs(u,k);
        }
    }
    return;
}
bool judge(){
    memset(part,0,sizeof(part));
    tot = 0;
    for (int i = 0;i < v.size();i++){
        int u = v[i];
        if (!part[u]){
            if (tot > 1){
                return false;
            }
            memset(vis,0,sizeof(vis));
            dfs(u,tot);
            tot++;
        }
    }
    return true;
}
void cal(){
    if (!judge()){
        return;
    }
    long long res = 0;
    for (int i = 1;i < n + 1;i++){
        long long tmp = 1e18;
        for (int j = 0;j < v.size();j++){
            tmp = min(tmp,dist(i,v[j]));
        }
        res = max(res,tmp);
    }
    ans = min(ans,res);
    return;
}
void dfs_search(int cur,int cnt){
    if (cur == n + 1){
        if (cnt == k){
            v.clear();
            for (int i = 1;i < n + 1;i++){
                if (used[i]){
                    v.push_back(i);
                }
            }
            cal();
        }
        return;
    }
    used[cur] = 1;
    dfs_search(cur + 1,cnt + 1);
    used[cur] = 0;
    dfs_search(cur + 1,cnt);
    return;
}
void solve(){
    cin >> n >> k;
    for (int i = 1;i < n + 1;i++){
        g[i].clear();
    }
    for (int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(used,0,sizeof(used));
    dfs_search(1,0);
    cout << ans << '\n';
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    while (t--){
        solve();
    }
    return 0;
}
