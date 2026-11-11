#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3 + 10 , INF = 1e18 , mod = 1e9 + 7;
vector<int> g[MAXN];
int n , k , ans;
int dis[MAXN];
bool flag[MAXN];
bool vis[MAXN];
void dfs2(int x){
    vis[x] = 1;
    for(auto u : g[x]){
        if(vis[u] || !flag[u]) continue;
        dfs2(u);
    }
}
int calc(){
    int cnt = 0 , res = 0;
    for(int i = 1 ; i <= n ; ++i){
        vis[i] = 0;
        dis[i] = INF;
    }
    queue<int> q;
    for(int i = 1 ; i <= n ; ++i){
        if(flag[i] && !vis[i]){
            dfs2(i);
            cnt++;
            if(cnt > 2) return INF;
        }
        if(flag[i]){
            q.push(i);
            dis[i] = 0;
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int u : g[x]){
            if(dis[u] == INF){
                dis[u] = dis[x] + 1;
                q.push(u);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        res = max(res , dis[i]);
    }
    return res;
}
void dfs(int x , int cnt){
    if(x == n + 2) return ;
    if(cnt == k){
        ans = min(ans , calc());
    }
    flag[x] = 1;
    dfs(x + 1 , cnt + 1);
    flag[x] = 0;
    dfs(x + 1 , cnt);
}
void solve(){
    cin>>n>>k;
    for(int i = 1 ; i <= n ; ++i)g[i].clear();
    for(int i = 1 ; i < n ; ++i){
        int u , v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = INF;
    dfs(1 , 0);
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    int c , t;
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
