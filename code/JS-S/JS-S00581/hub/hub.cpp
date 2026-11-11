#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,maxdep[N],root,f[N][22],depth[N],dfn[N],cnt,tot,sz[N],ans;
bool flag[N];
int vt[N];
vector<int>G[N],g[N];
int lca(int x,int y){
    if(depth[x]<depth[y]) swap(x,y);
    for(int i=21;i>=0;i--)
        if(depth[f[x][i]]>=depth[y])
            x=f[x][i];
    if(x==y) return x;
    for(int i=21;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
void Dfs(int x,int father,int deep){
    f[x][0]=father;depth[x]=deep;dfn[x]=++tot;
    for(int i=1;i<22;i++)
        f[x][i]=f[f[x][i-1]][i-1];
    maxdep[x]=0;
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(y==father) continue;
        Dfs(y,x,deep+1);maxdep[x]=max(maxdep[x],maxdep[y]+1);
    }
    return;
}
void cut(int x,int deep,int lim){
    if(deep==lim) return;
    for(int i=0;i<G[x].size();i++){
        int y=G[x][i];
        if(y==f[x][0]||!flag[y]) continue;
        cut(y,deep+1,lim);
    }
    if(maxdep[x]>lim) flag[x]=0;
    return;
}
void dfs2(int x,int father){
    sz[x]=flag[x];
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==father) continue;
        dfs2(y,x);sz[x]+=sz[y];
    }
    return;
}
void dfs(int x,int father,int dwn,int lim){
    if((depth[x]-depth[father]-1)<lim) ans=min(ans,dwn+sz[x]);
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==father) continue;
        dfs(y,x,dwn+sz[x]-sz[y],lim);
    }
    return;
}
bool check(int lim){
    cnt=tot=0;ans=n+2;
    for(int i=1;i<=n;i++)
        flag[i]=(bool)(maxdep[i]>=lim);
    if(!flag[root]) return 1;
    cut(root,0,lim);
    for(int i=1;i<=n;i++)
        if(flag[i])
            cnt++,vt[++tot]=i;
    sort(vt+1,vt+1+tot,[](int x,int y){return dfn[x]<dfn[y];});
    for(int i=1;i<cnt;i++) vt[++tot]=lca(vt[i],vt[i+1]);
    sort(vt+1,vt+1+tot,[](int x,int y){return dfn[x]<dfn[y];});
    tot=unique(vt+1,vt+1+tot)-vt-1;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<tot;i++)
        g[lca(vt[i],vt[i+1])].push_back(vt[i+1]);
    dfs2(vt[1],0);dfs(vt[1],0,0,lim);
    return ans<=m;
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c,T;cin>>c>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<n;i++){
            int x,y;cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(n==m){
            cout<<0<<'\n';
            continue;
        }
        if(n==m+1){
            cout<<1<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
            if(G[i].size()==1)
                root=i;
        tot=0;
        Dfs(root,0,0);
        int l=0,r=n,mid;
        while(l+1<r){
            mid=(l+r)>>1;
            if(check(mid)) l=mid;
            else r=mid;
        }
        cout<<l<<'\n';
    }
    return 0;
}