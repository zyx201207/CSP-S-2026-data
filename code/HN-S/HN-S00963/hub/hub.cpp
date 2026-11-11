#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int c,t,n,k,ans,inf=1e9;
int a[N],b[N],vis[N],dis[N];
vector<int> g[N];
void dfs2(int x){
    vis[x]=2;
    for(int y:g[x])
        if(vis[y]==1) dfs2(y);
    return;
}
void dfs3(int x,int fa,int dep){
    dis[x]=min(dis[x],dep);
    for(int y:g[x]){
        if(y==fa) continue;
        dfs3(y,x,dep+1);
    }
    return;
}
void dfs(int x){
    if(x==k+1){
        for(int i=1;i<=n;i++) vis[i]=0,dis[i]=inf;
        for(int i=1;i<=k;i++) vis[a[i]]++;
        for(int i=1;i<=n;i++) if(vis[i]>1) return;
        int tot=0;
        for(int i=1;i<=n;i++)
            if(vis[i]==1) dfs2(i),tot++;
        if(tot>2) return;
        for(int i=1;i<=n;i++)
            if(vis[i]) dfs3(i,0,0);
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
        ans=min(ans,mx);
        return;
    }
    for(int i=1;i<=n;i++){
        a[x]=i;
        dfs(x+1);
    }
    return;
}
void solve(){
    cin>>n>>k;ans=inf;
    for(int i=1;i<=n;i++) g[i].clear();
    if(n<=10){
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1);
        cout<<ans<<"\n";
        return;
    } 
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}