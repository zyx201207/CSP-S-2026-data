#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,ans,d[35];
bool cl[35],vis[35],vis2[35];
vector <int> e[2000005];
void dfs(int u){
    vis[u]=1;
    for(int v:e[u]){
        if(cl[v]&&!vis[v]) dfs(v);
    }
}
void dfs2(int u){
    if(cl[u]){
        d[u]=0;
        return;
    }
    vis2[u]=1;
    d[u]=1;
    int mn=1e9;
    for(int v:e[u]){
        if(!vis2[v]) dfs2(v);
        mn=min(d[v],mn);
    }
    d[u]+=(mn==1e9)?0:mn;
}
int main(){
    freopen("hub.in","r",stdin);
    freoepn("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        ans=1e9;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            e[u].push_back(v),e[v].push_back(u);
        }
        for(int st=1;st<(1<<n);st++){
            if(__builtin_popcount(st)!=k) continue;
            for(int i=1;i<=n;i++) cl[i]=0,d[i]=0,vis[i]=0,vis2[i]=0;
            for(int i=1;i<=n;i++){
                if((st>>(i-1))&1) cl[i]=1;
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(cl[i]&&!vis[i]){
                    cnt++;
                    dfs(i);
                }
            }
            if(cnt>2) continue;
            for(int i=1;i<=n;i++){
                if(!cl[i]&&!vis2[i]){
                    dfs2(i);
                }
            }
            int mx=0;
            for(int i=1;i<=n;i++) mx=max(mx,d[i]);
            ans=min(ans,mx);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
