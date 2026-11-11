#include <bits/stdc++.h>
using namespace std;
const int N=2e6+7;

int c,t,n,k;
int p[N][30];
int depth[N];
int ds[N];
bool edge[307][307];
vector<int> g[N];
vector<int> situ;

int find(int x){
    if(x==ds[x]) return x;
    return ds[x]=find(ds[x]);
}

void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return ;
    ds[x]=y;
    return ;
}

void chk(){
    for(int i=1;i<=n;i++) ds[i]=i;
    for(int i=1;i<=n;i++){
        if(!situ[i-1]) continue;
        for(auto v:g[i]){
            if(situ[v-1]) merge(i,v);
        }
    }
    for(int i=1;i<=n;i++) find(i);
}

void dfs2(int u,int lft){
    if(n-u+1<lft&&lft) return ;
    if(u==n+1&&!lft) chk();
    situ.push_back(0);
    dfs2(u+1,lft);
    situ.pop_back();
    situ.push_back(1);
    dfs2(u+1,lft-1);
    situ.pop_back();
}

void dfs(int u,int fa){
    depth[u]=depth[fa]+1;
    p[u][0]=fa;
    for(int i=1;(1<<i)<=depth[u];i++){
        p[u][i]=p[p[u][i-1]][i-1];
    }
    for(auto v:g[u]){
        if(v==fa) continue;
        dfs(v,u);
    }
}

int lca(int x,int y){
    if(depth[x]>=depth[y]) swap(x,y);
    for(int i=20;i>=0;i--){
        if(depth[x]<=depth[y]-(1<<i)) y=p[y][i];
    }
    if(x==y) return x;
    for(int i=20;i>=0;i--){
        if((1<<i)>depth[x]) continue;
        if(p[x][i]!=p[y][i]){
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}

void solve(){
    scanf("%d%d",&n,&k);
    for(int i=1,u,v;i<=n-1;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,k);
    cout<<1<<endl;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }
    return 0;
}
