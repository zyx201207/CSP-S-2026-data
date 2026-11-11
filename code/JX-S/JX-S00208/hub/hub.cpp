#include<bits/stdc++.h>
using namespace std;

const int N=15;
int c,T;
int n,k;
int dep[N],fa[N],b[N][N],tag[N];
vector<int> g[N];

struct BSU{
    int fa[N];
    void init(int k){
        for(int i=1;i<=k;i++) fa[i]=i;
    }
    int find(int x){
        while(fa[x]!=x) x=fa[x]=fa[fa[x]];
        return x;
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        fa[fx]=fy;
    }
}bsu;

void dfs(int u,int f){
    dep[u]=dep[f]+1,fa[u]=f;
    for(int v:g[u]){
        if(v==f) continue;
        dfs(v,u);
    }
}

int lca(int x,int y){
    while(x!=y){
        if(dep[x]>dep[y]) x=fa[x];
        else y=fa[y];
    }
    return x;
}

void solve(){
    int ans=1e9;
    memset(b,0,sizeof b);
    memset(dep,0,sizeof dep);
    memset(fa,0,sizeof fa);
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        b[u][v]=b[v][u]=1;
    }
    dfs(1,0);
    for(int S=0;S<(1<<n);S++){
        if(__builtin_popcount(S)!=k) continue;
        bsu.init(n);
        memset(tag,0,sizeof tag);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            if(!((S>>i)&1)||!((S>>j)&1)) continue;
            if(b[i+1][j+1]) bsu.merge(i+1,j+1);
        }
        int cnt=0,mx=0;
        for(int i=0;i<n;i++) if(((S>>i)&1)&&tag[bsu.find(i+1)]==0) tag[bsu.find(i+1)]=1,cnt++;
        if(cnt>2) continue;
        for(int i=1;i<=n;i++){
            int res=1e9;
            for(int j=0;j<n;j++){
                if(!((S>>j)&1)) continue;
                res=min(res,dep[i]+dep[j+1]-dep[lca(i,j+1)]*2);
            }
            //cout<<res<<"\n";
            mx=max(mx,res);
        }
        ans=min(ans,mx);
    }
    cout<<ans<<"\n";
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
//g++ -o main hub.cpp -O2 -std=c++14 -static