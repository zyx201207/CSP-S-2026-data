#include<bits/stdc++.h>
using namespace std;
using i64=long long;
void Min(i64&x,const i64&y){y<x&&(x=y,0);}
int Cid;
const int N=1e6+10;
int U[N],V[N],dep[N];
int mx0[N],mx1[N],t0[N],t1[N];
vector<int>e[N];
void dfs1(int u,int fa,int op){
    mx0[u]=dep[u];
    t0[u]=mx1[u]=t1[u]=0;
    for(int v:e[u])if(v!=fa){
        dep[v]=dep[u]+op;dfs1(v,u,op);
        if(mx0[v]>mx1[u])mx1[u]=mx0[v],t1[u]=v;
        if(mx1[u]>mx0[u])swap(mx1[u],mx0[u]),swap(t1[u],t0[u]);
    }
    return;
}
int dfs2(int u,int d){
    if(d==dep[u])return u;
    return dfs2(t0[u],d);
}
inline bool cmp(int x,int y){return x>y;}
void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<n;i++)cin>>U[i]>>V[i];
    if(k==n)return cout<<0<<'\n',void();
    if(Cid==13||Cid==14){
        if(k>=n/2)cout<<1<<'\n';
        else cout<<(n/2-k+3)/4+1<<'\n';
        return;
    }
    int ans=n;
    for(int ban=1,rt;ban<n;ban++){
        int u=U[ban],v=V[ban];
        for(int i=1;i<=n;i++)
            dep[i]=0,e[i].clear();
        for(int i=1;i<n;i++)if(i!=ban)
            e[U[i]].push_back(V[i]),
            e[V[i]].push_back(U[i]);
        dfs1(u,v,1);
        rt=dfs2(u,(mx0[u]-mx1[u])/2);
        dep[rt]=(mx0[u]+mx1[u]+1)/2;
        dfs1(rt,0,-1);
        dep[rt]=0;
        dfs1(v,u,1);
        rt=dfs2(v,(mx0[v]-mx1[v])/2);
        dep[rt]=(mx0[v]+mx1[v]+1)/2;
        dfs1(rt,0,-1);
        dep[rt]=0;
        sort(dep+1,dep+n+1,cmp);
        ans=min(ans,dep[k-1]+1);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>Cid>>T;
    while(T--)solve();
    return 0;
}
//g++ -g hub.cpp -o exe -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined