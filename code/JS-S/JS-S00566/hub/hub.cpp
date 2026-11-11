#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int C,T,n,k,fr[N][21],d[N],ans,f[N];
vector<int> g[N],c;
#define pb emplace_back
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x);y=find(y);
    f[x]=y;
}
void dfs(int x,int fa){
    fr[x][0]=fa;d[x]=d[fa]+1;
    for(int i=1;i<=20;i++) fr[x][i]=fr[fr[x][i-1]][i-1];
    for(int y:g[x]) if(y!=fa) dfs(y,x);
}
int lca(int x,int y){
    if(d[x]<d[y]) swap(x,y);
    for(int i=20;~i;i--) if(d[fr[x][i]]>=d[y]) x=fr[x][i];
    if(x==y) return x;
    for(int i=20;~i;i--) if(fr[x][i]!=fr[y][i]) x=fr[x][i],y=fr[y][i];
    return fr[x][0];
}
int dis(int x,int y){
    int l=lca(x,y);
    return d[x]-d[l]+d[y]-d[l];
}
void solve(int x,int cnt){
    if(x>n){
        if(cnt<k) return ;
        for(int u:c) f[u]=u;
        for(int u:c){
            for(int v:c) if(u!=v&&(fr[u][0]==v||fr[v][0]==u)) merge(u,v);
        }
        int ret=0;
        for(int u:c) ret+=(find(u)==u);
        if(ret>2) return ;
        ret=0;
        for(int i=1,tt;i<=n;i++){
            tt=1e9;
            for(int u:c) tt=min(tt,dis(u,i));
            ret=max(ret,tt);
        }
        ans=min(ans,ret);
        return ;
    }
    solve(x+1,cnt);
    if(cnt<k) c.pb(x),solve(x+1,cnt+1),c.pop_back();
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>C>>T;
    while(T--){
        cin>>n>>k;ans=1e9;c.clear();
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1,u,v;i<n;i++) cin>>u>>v,g[u].pb(v),g[v].pb(u);
        dfs(1,0);solve(1,0);cout<<ans<<'\n';
    }
    return 0;
}