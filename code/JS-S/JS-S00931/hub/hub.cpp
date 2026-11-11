#include<bits/stdc++.h>
using namespace std;
int cid;

const int N=1000005;
int n,k,sz,ans,v1[N],v2[N],deg[N];
vector<int>G[N];

void dfs(int u,int f){
    sz++;
    for(int v:G[u])if(v!=f){
        dfs(v,u);
        deg[u]++,deg[v]++;
    }
}

void gat(int u,int ban,int vl[]){
    for(int i=1;i<=n;i++)deg[i]=0;
    sz=0,dfs(u,ban);
    queue<pair<int,int>>q;
    for(int i=1;i<=n;i++)if(deg[i]==1)q.emplace(i,1);
    int tot=0,mxd=0;
    while(!q.empty()){
        auto[u,d]=q.front();q.pop();
        if(deg[u]!=1)continue;
        vl[mxd=d]=min(sz-1,++tot);
        for(int v:G[u])if((--deg[v])==1)q.emplace(v,d+1);
    }
    for(int i=mxd;i<=n;i++)vl[i]=sz-1;
}

void calc(int u,int v){
    for(int i=1;i<=n;i++)v1[i]=v2[i]=0;
    gat(u,v,v1),gat(v,u,v2);
    for(int i=1;i<=n;i++)if(n-v1[i]-v2[i]<=k){
        // cerr<<i<<endl;
        ans=min(ans,i);
        // cerr<<ans<<endl;
    }
}
/*
vector<int>diam;

namespace dimfd{
    int fa[N],dep[N];
    void dfs(int u,int f){
        fa[u]=f;
        dep[u]=dep[f]+1;
        for(int v:G[u])if(v!=f)dfs(v,u);
    }
    void fd(){
        dfs(1,0);
        int s=max_element(dep+1,dep+n+1)-dep;
        dfs(s,0);
        int t=max_element(dep+1,dep+n+1)-dep;
        while(t!=s)diam.push_back(t),t=fa[t];
        diam.push_back(s);
    }
}
*/

namespace LCA{
    int fa[N],top[N],dep[N],sz[N],son[N];
    void dfs(int u,int f){
        fa[u]=f;
        dep[u]=dep[f]+1;
        sz[u]=1;
        son[u]=0;
        for(int v:G[u])if(v!=f){
            dfs(v,u);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]])son[u]=v;
        }
    }
    void efs(int u,int f,int t){
        top[u]=t;
        if(son[u])efs(son[u],u,t);
        for(int v:G[u])if(v!=f&&v!=son[u])efs(v,u,v);
    }
    void bld(){
        dfs(1,0);
        efs(1,0,1);
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])u=fa[top[u]];
            else v=fa[top[v]];
        }
        return dep[u]<dep[v]?u:v;
    }
    int dist(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
}

struct Diam{
    int u,v,d;
    Diam(){u=v=d=0;}
    Diam(int x){u=v=x,d=0;}
    void add(int x){
        if(!x)return;
        if(!u){
            u=v=x;
            return;
        }
        pair<int,int>t[3]={{u,v},{u,x},{v,x}};
        int di[3]={d,LCA::dist(u,x),LCA::dist(v,x)};
        int p=max_element(di,di+3)-di;
        tie(u,v)=t[p];
        d=di[p];
    }
    void add(Diam d){
        add(d.u),add(d.v);
    }
}in[N],ou[N],pr[N],sf[N];

void hg1(int u,int f){
    in[u]=Diam(u);
    for(int v:G[u])if(v!=f){
        hg1(v,u);
        in[u].add(in[v]);
    }
}

void hg2(int u,int f){
    Diam o(u);
    for(int v:G[u])if(v!=f){
        pr[v]=o;
        o.add(in[v]);
    }
    reverse(G[u].begin(),G[u].end());
    o=Diam();
    for(int v:G[u])if(v!=f){
        sf[v]=o;
        o.add(in[v]);
    }
    reverse(G[u].begin(),G[u].end());
    for(int v:G[u])if(v!=f){
        ou[v]=ou[u];
        ou[v].add(pr[v]);
        ou[v].add(sf[v]);
    }
    for(int v:G[u])if(v!=f)hg2(v,u);
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // {
    //     LCA::bld();
    //     hg1(1,0);
    //     ou[1]=Diam();
    //     hg2(1,0);
    //     for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cerr<<i<<" "<<j<<" "<<LCA::dist(i,j)<<" "<<LCA::lca(i,j)<<endl;
    //     for(int i=1;i<=n;i++)cerr<<i<<" "<<in[i].d<<endl;
    // }

    if(cid==13||cid==14){
        int m=(n-1)/2;
        if(m<=k)cout<<1<<endl;
        else cout<<(m-k)/4+2<<endl;
        return;
    }
    ans=n;
    for(int i=1;i<=n;i++)v1[i]=0;
    gat(1,0,v1);
    for(int i=1;i<=n;i++)if(n-v1[i]<=k)ans=min(ans,i);
    if(cid<=10){
        for(int u=1;u<=n;u++)for(int v:G[u])if(u<v)calc(u,v);
    }else{
        for(int i=1;i<=n;i++){
            in[i]=ou[i]=pr[i]=sf[i]=Diam();
        }
        LCA::bld();
        hg1(1,0);
        hg2(1,0);
        for(int u=2;u<=n;u++){
            int d1=in[u].d,d2=ou[u].d;
            ans=min(ans, max((d1+1)/2, (d2+1)/2));
        }
    }
    cout<<ans<<endl;
}

int main(){
#ifndef LOC
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
#endif
    cin.tie(0)->sync_with_stdio(0);
    int T;cin>>cid>>T;
    while(T--)solve();
    return 0;
}