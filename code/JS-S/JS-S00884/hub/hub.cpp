#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[1000003];
bool in[1000003],vis[1000003];
int dis[1000003];
void dfs(int u){
    vis[u]=1;
    for(auto v:g[u])
        if(!vis[v] and in[v]) dfs(v);
}
void dfs2(int u,int dep,int fa){
    dis[u]=min(dis[u],dep);
    for(auto v:g[u]){
        if(v!=fa and !in[v]) dfs2(v,dep+1,u);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans=1e9;
        for(int mask=0;mask<(1<<n);mask++){
            if(__builtin_popcount(mask)!=k) continue;
            for(int i=1;i<=n;i++){
                vis[i]=in[i]=0;
            }
            for(int i=1;i<=n;i++)
                if(mask&(1<<i-1)) in[i]=1;
            int block=0;
            for(int i=1;i<=n;i++)
                if(in[i])
                    if(!vis[i]){
                        block++;
                        dfs(i);
                    }
            if(block>2) continue;
            for(int i=1;i<=n;i++) dis[i]=1e9;
            for(int i=1;i<=n;i++)
                if(in[i]) dfs2(i,0,0);
            int sum=0;
            for(int i=1;i<=n;i++) sum=max(sum,dis[i]);
            ans=min(ans,sum);
        }
        cout<<ans<<'\n';
    }
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
