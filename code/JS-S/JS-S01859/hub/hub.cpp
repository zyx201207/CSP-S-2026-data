#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k,d[N],fa[N][20];
void dfs(int u,int f){
    d[u]=d[f]+1;
    fa[u][0]=f;
    for(int i=1;i<20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int v:tr[u]){
        if(v==f)continue;
        dfs(v,u);
    }
}inline int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    for(int i=19;i>=0;i++)if(d[fa[u][i]]>d[v])u=fa[u][i];
    if(d[u]>d[v])u=fa[u][0];
    if(u==v)return u;
    for(int i=19;i>=0;i++)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}vector<int>tr[N];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int t;
    scanf("%d%d",&t,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)tr[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            tr[u].push_back(v);
            tr[v].push_back(u);
        }printf("%d\n",((n+1)/2-k)/4+1);
    }return 0;
}