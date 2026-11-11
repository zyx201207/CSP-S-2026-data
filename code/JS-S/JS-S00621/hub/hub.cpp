#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,lg=21,inf=1e9;
int c,t;
int n,k,dep[N];
int fa[N][lg];
vector<int>g[N];
void dfs(int u,int fa_){
    dep[u]=dep[fa_]+1,fa[u][0]=fa_;
    for(int i=1;i<lg;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=0;i<g[u].size();++i){
        int v=g[u][i];
        if(v==fa_)continue;
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=lg-1;i;--i)if(d>>i&1)u=fa[u][i];
    if(u==v)return u;
    for(int i=lg-1;i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dep[0]=-1;
        dfs(1,0);
        int ans=inf;
        for(int i=1;i<=n;++i)
        for(int j=1;j<i;++j){
            int res=0;
            for(int k=1;k<=n;++k){
                res=max(res,min(dis(k,i),dis(k,j)));
            }
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
//Many years after I graduated, in the mild light of sunset, I recalled a moment when I secretly wrote down this sentence, exactly, the sentence of my distant childhood...
