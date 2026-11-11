#include<iostream>
#include<vector>
#include<numeric>
#include<cstdio>
using namespace std;
inline int find(int x,vector<int>&dsu){
    return x==dsu[x]?x:dsu[x]=find(dsu[x],dsu);
}
int main(){
    #ifndef PSD
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    #endif // PSD
    cin.tie(nullptr)->sync_with_stdio(false);
    int c,T;
    cin>>c>>T;
    while(T--){
        int n,K;
        cin>>n>>K;
        vector<vector<int>> g(n+1),f(__lg(n)+1,vector<int>(n+1));
        vector<vector<bool>> con(n+1,vector<bool>(n+1));
        vector<int> dep(n+1);
        for(int i=1,u,v;i<n;i++)
            cin>>u>>v,g[u].push_back(v),g[v].push_back(u),
            con[u][v]=con[v][u]=true;
        auto dfs=[&](auto&self,int root,int fa)->void{
            dep[root]=dep[fa]+1,f[0][root]=fa;
            for(int v:g[root])if(v!=fa)
                self(self,v,root);
        };
        dfs(dfs,1,0);
        for(int j=1;(1<<j)<=n;j++)
            for(int i=1;i<=n;i++)
                f[j][i]=f[j-1][f[j-1][i]];
        auto lca=[&](int u,int v){
            if(dep[u]<dep[v])swap(u,v);
            while(dep[u]!=dep[v])u=f[__lg(dep[u]-dep[v])][u];
            if(u==v)return u;
            for(int i=__lg(dep[u]);i>=0;i--)if(f[i][u]!=f[i][v])
                u=f[i][u],v=f[i][v];
            return f[0][u];
        };
        int ans=2e9;
        vector<int> pts;
        vector<bool> vis(n+1);
        auto dfs2=[&](auto&self,int stp)->void{
            if(pts.size()==K){
                int mx=0;
                vector<int> dsu(n+1);
                iota(dsu.begin(),dsu.end(),0);
                for(int j=0;j<K;j++)for(int k=j+1;k<K;k++)
                    if(con[pts[k]][pts[j]]&&find(pts[k],dsu)!=find(pts[j],dsu))
                        dsu[find(pts[j],dsu)]=find(pts[k],dsu);
                int cnt=0;
                for(int j=1;j<=n;j++)cnt+=find(j,dsu)==j;
                if(cnt==n-K+1||cnt==n-K+2){
                    /*cout<<cnt<<':';
                    for(int j:pts)cout<<j<<' ';*/
                    for(int j=1;j<=n;j++)if(!vis[j]){
                        int mn=2e9;
                        for(int k:pts)
                            mn=min(mn,dep[j]+dep[k]-2*dep[lca(j,k)]);
                        mx=max(mx,mn);
                    }
                    //cout<<':'<<mx<<'\n';
                    ans=min(ans,mx);
                }
                return;
            }
            if(stp==n+1)return;
            self(self,stp+1);
            vis[stp]=true,pts.push_back(stp);
            self(self,stp+1);
            vis[stp]=false,pts.pop_back();
        };
        dfs2(dfs2,1);
        cout<<ans<<'\n';
    }
    return 0;
}
