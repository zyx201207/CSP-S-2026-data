#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int ds[N][N];
vector<int> ht[N];
int n,k;
void dfs(int u,int fa,int s){
    ds[s][u]=ds[s][fa]+1;
    for(int v:ht[u]){
        if(v==fa) continue;
        dfs(v,u,s);
    }
}
vector<int> p;
int ans=1e9;
int fa[N],fl[N];
int find(int x){return fa[x]==x ? x : fa[x]=find(fa[x]);}
void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y) return ;
    fa[x]=y;
}
void hutao(int s,int o=1){
    if(s>k){
        for(int u:p) fa[u]=u;
        for(int u:p) for(int v:ht[u]) if(fl[v]==1) merge(u,v);
        int o=0;
        for(int i=1;i<(int)p.size();i++){
            if(find(p[i])!=find(p[0]) && o!=0 && find(p[i])!=o) return ;
            if(find(p[i])!=find(p[0])) o=find(p[i]);
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            int mi=1e9;
            for(int u:p) mi=min(mi,ds[u][i]);
            mx=max(mx,mi);
        }
        ans=min(ans,mx);
        return ;
    }
    for(int i=o;i<=n;i++) fl[i]=1,p.push_back(i),hutao(s+1,i+1),p.pop_back(),fl[i]=0;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,_;scanf("%d%d",&c,&_);
    while(_--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) ht[i].clear();
        for(int i=1;i<n;i++){
            int u,v;scanf("%d%d",&u,&v);
            ht[u].push_back(v);
            ht[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            ds[i][0]=-1;
            dfs(i,0,i);
        }ans=1e9;
        hutao(1);
        printf("%d\n",ans);
    }
    return 0;
}