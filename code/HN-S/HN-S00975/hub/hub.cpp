#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
vector<int>v[1000010];
int ok[1000010],vis[1000010],dis[1000010];
void dfs(int sx,int f){
    vis[sx]=1;
    for(auto y:v[sx]){
        if(y==f||ok[y]==0)continue;
        dfs(y,sx);
    }
}
void dfs2(int sx,int f,int jl){
    dis[sx]=min(dis[sx],jl);
    for(auto y:v[sx]){
        if(y==f)continue;
        dfs2(y,sx,jl+1);
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int x=1;x<=n;x++)v[x].clear();
        for(int x=1;x<n;x++){
            int u,w;
            cin>>u>>w;
            v[u].push_back(w);
            v[w].push_back(u);
        }
        int ans=n+1;
        for(int x=1;x<(1<<n);x++){
            int tot=0;
            for(int y=0;y<n;y++){
                if(x&(1<<y))ok[y+1]=1,tot++;
                else ok[y+1]=0;
            }
            if(tot>k)continue;
            tot=0;
            for(int y=1;y<=n;y++)vis[y]=0;
            for(int y=1;y<=n;y++){
                if(vis[y]==1||ok[y]==0)continue;
                dfs(y,0);tot++;
            }
            if(tot>2)continue;
            for(int y=1;y<=n;y++)dis[y]=n+1;
            for(int y=1;y<=n;y++){
                if(ok[y]==1){
                    dfs2(y,0,0);
                }
            }
            int t=0;
            for(int y=1;y<=n;y++)t=max(t,dis[y]);
            ans=min(ans,t);
        }
        cout<<ans<<'\n';
    }
}