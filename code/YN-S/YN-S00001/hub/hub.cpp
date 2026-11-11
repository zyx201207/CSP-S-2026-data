// [15,15]
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
int n,k,ans = 1e18;
vector<int> ve[N];
bool vis[N],v[N];
queue<pair<int,int>> q;
void dfs(int now){
    if(now == k){
        int maxx = 0;
        for(int i = 1;i <= n;i++){
            memset(v,0,sizeof v);
            while(!q.empty()) q.pop();
            q.push({i,0});
            while(!q.empty()){
                auto [u,st] = q.front();
                if(vis[u]) break;
                q.pop();
                if(v[u]) continue;
                v[u] = 1;
                for(auto vv : ve[u]){
                    if(!v[vv]) q.push({vv,st + 1});
                }
            }
            maxx = max(maxx,q.front().second);
        }
        ans = min(ans,maxx);
        return;
    }
    for(int i = 1;i <= n;i++){
        if(vis[i]){
            for(auto vv : ve[i]){
                if(vis[vv]) continue;
                vis[vv] = 1;
                dfs(now + 1);
                vis[vv] = 0;
            }
        }
    }
}
void solve(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++) ve[i].clear();
    for(int i = 1;i < n;i++){
        int u,v; cin >> u >> v;
        ve[u].pb(v);
        ve[v].pb(u);
    }
    ans = 1e18;
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            vis[i] = vis[j] = 1;
            dfs(2);
            vis[i] = vis[j] = 0;
        }
    }
    cout << ans << "\n";
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1; cin >> tid >> T;
    while(T--) solve();
    return 0;
}