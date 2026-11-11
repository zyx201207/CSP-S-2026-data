#include<bits/stdc++.h>
#define For(i,j,k) for(auto i=(j);i<=(k);i++)
#define dFor(i,j,k) for(auto i=(j);i>=(k);i--)
using namespace std;
#define MAXN 1000005
#define MAXL 21
#define INF (1<<30)
int n,k;
vector<int> e[MAXN];
int fa[MAXN],dep[MAXN],dfn[MAXN],cnt;
int st[MAXL][MAXN];
void dfs(int u,int f){
    fa[u]=f;
    dep[u]=dep[f]+1;
    dfn[u]=++cnt;
    st[0][cnt]=f;
    for(int v:e[u]){
        if(v==f) continue ;
        dfs(v,u);
    }
}
inline int get(int u,int v){
    return dfn[u]<dfn[v]?u:v;
}
inline int LCA(int u,int v){
    if(u==v) return u;
    u=dfn[u],v=dfn[v];
    if(u>v) swap(u,v);
    u++;
    int x=__lg(v-u+1);
    return get(st[x][u],st[x][v-(1<<x)+1]);
}
inline int dis(int u,int v){
    return dep[u]+dep[v]-dep[LCA(u,v)]*2;
}
bool vis[MAXN];
void BF(){
    int ans=INF;
    For(s,0,(1<<n)-1){
        int sum=0;
        For(i,1,n){
            vis[i]=(s>>(i-1))&1;
            sum+=vis[i];
        }
        if(sum!=k) continue ;
        For(u,1,n){
            for(int v:e[u]){
                if(v==fa[u]) continue ;
                sum-=(vis[u]&&vis[v]);
            }
        }
        if(sum>2) continue ;
        vector<int> has;
        For(u,1,n){
            if(vis[u]){
                has.push_back(u);
            }
        }
        int now=0;
        For(u,1,n){
            int Min=INF;
            for(int v:has){
                Min=min(Min,dis(u,v));
            }
            now=max(now,Min);
        }
        ans=min(ans,now);
    }
    cout<<ans<<'\n';
}
void solve(){
    cin>>n>>k;
    For(i,1,n){
        e[i].clear();
        fa[i]=dep[i]=dfn[i]=0;
    }
    cnt=0;
    For(i,1,n-1){
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    For(i,1,__lg(n)){
        For(j,1,n-(1<<i)+1){
            st[i][j]=get(st[i-1][j],st[i-1][j+(1<<(i-1))]);
        }
    }
    if(n<=10){
        BF();
        return ;
    }else{
        cout<<1<<'\n';
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
g++ -O2 -std=c++14 -Wall -Wextra -Wshadow -o hub hub.cpp
*/