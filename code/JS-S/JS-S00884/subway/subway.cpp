#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[5003],path[5003];
int p,tot,s,t;
bool vis[5003];
void dfs(int u){
    if(u==st){
        path[++tot]=p;
        return;
    }
    for(auto v:g[u]){
        if(vis[v]) continue;
        p.push_back(v);
        vis[v]=1;
        dfs(v);
        p.pop_back();
        vis[v]=0;
    }
}
int t[5003][5003];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        int k,lst=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u;
            cin>>u>>t[i][j];
            if(!lst) lst=u;
            else g[lst].push_back(u);
        }
    }
    while(q--){
        cin>>s>>t;
        for(int i=1;i<=m;i++) vis[i]=0;
        p.clear();
        vis[s]=1;
        p.push_back(s);
        tot=0;
        dfs(s);

    }
}
