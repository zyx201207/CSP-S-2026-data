#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,_,n,k,ans,cnt;
int a[N],vis[N],dis[N];
vector<int> g[N];
void dfs(int u,int fa){
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        if(vis[v] || !a[v]) continue;
        dfs(v,u);
    }
}
bool chk(){
    int res=0,gs=0;
    for(int i=1;i<=n;i++) gs+=a[i];
    if(gs!=k) return false;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++) if(!vis[i] && a[i]) dfs(i,0),res++;
    if(res<=2) return true;
    else return false;
}
void dfs2(int u,int fa){
    dis[u]=min(dis[u],dis[fa]+1);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs2(v,u);
    }
}
void dg(int dep){
    if(dep>n){
        if(!chk()) return ;
        for(int i=1;i<=n;i++){
            if(!a[i]) dis[i]=1e15;
            else dis[i]=0;
        }
        for(int i=1;i<=n;i++) if(a[i]) dfs2(i,0);
        int mx=0;
        for(int i=1;i<=n;i++) mx=max(mx,dis[i]);
        ans=min(ans,mx);
        return ;
    }
    a[dep]=0;
    dg(dep+1);
    a[dep]=1;
    dg(dep+1);
}
void work(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(c<=3){
        ans=1e15;
        dg(1);
        cout<<ans<<'\n';
        return ;
    }
    if(c==13 || c==14){
        if(k>=n) cout<<0<<'\n';
        else if(k>=(n/2)) cout<<1<<'\n';
        else{
            int cd=((n+1)/2+1);
            cout<<(cd-k+3)/4<<'\n';
        }
        return ;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>_;
    while(_--) work();
    return 0;
}
