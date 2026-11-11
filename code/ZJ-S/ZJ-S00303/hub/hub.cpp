#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PII pair<int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f
using namespace std;
int C,_,fa[1000003],dis[1000003];
bool vis[1000003];
vector<int>g[1000003];
vector<bool>ord;
inline int find(int x){return fa[x]==x?x:fa[x] = find(fa[x]);}
inline void dfs(int u,int f){
    if(!ord[u-1])dis[u] = min(dis[u],dis[f]+1);
    else dis[u] = 0;
    for(auto v:g[u])
        if(v!=f)dfs(v,u);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>_;
    while(_--){
        int n,k,ans = inf;cin>>n>>k;
        for(int i = 1;i<=n;i++)g[i].clear();
        for(int i = 1;i<n;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ord.clear();
        for(int i = 1;i<=n-k;i++)ord.push_back(0);
        for(int i = 1;i<=k;i++)ord.push_back(1);
        do{
            for(int i = 1;i<=n;i++)fa[i] = i,vis[i] = 0,dis[i] = inf;
            int tot = k;
            for(int u = 1;u<=n;u++)
                if(ord[u-1])
                    for(auto v:g[u])
                        if(ord[v-1])
                            if(find(v)!=find(u))
                                tot--,fa[fa[v]] = fa[u];
            if(tot>2)continue;
            for(int i = 1;i<=n;i++)
                if(ord[i-1] && !vis[fa[i]])vis[fa[i]] = 1,dfs(fa[i],0);
            int tmp = 0;
            for(int i = 1;i<=n;i++)tmp = max(tmp,dis[i]);
            ans = min(ans,tmp);
        }while(next_permutation(ord.begin(),ord.end()));
        cout<<ans<<endl;
    }
    return 0;
}
/*
g++ -o hub/hub hub/hub.cpp -O2 -std=c++14 -static -Wall -Wshadow
*/