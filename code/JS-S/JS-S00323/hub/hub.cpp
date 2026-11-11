#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N=1e6+10;
int c,T,n,k,ans,pos,mx[N],id[N],smx[N],w[N],fa[N];
vector<int>e[N];
void init(const int u){for(int v:e[u])if(v!=fa[u])fa[v]=u,init(v);}
void dfs(const int u){
    mx[u]=smx[u]=id[u]=0;
    for(int v:e[u])if(v!=fa[u] && v!=pos){
        dfs(v);
        if(mx[v]+1>mx[u])smx[u]=mx[u],mx[u]=mx[v]+1,id[u]=v;
        else if(mx[v]+1>smx[u])smx[u]=mx[v]+1;
    }
}
int smax(int a,int b,int c){
    if(a>b)swap(a,b);
    if(a>c)swap(a,c);
    if(b>c)swap(b,c);
    return b;
}
void rdfs(const int u,const int W){
    w[u]=smax(W,mx[u],smx[u])+1;
    for(int v:e[u])if(v!=fa[u] && v!=pos)rdfs(v,max(W,v==id[u]?smx[u]:mx[u])+1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&k),ans=n;
        for(int i=1,u,v;i<n;++i){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        init(1);
        for(pos=1;pos<=n;++pos){
            dfs(1),rdfs(1,0);
            if(pos!=1)dfs(pos),rdfs(pos,0);
            sort(w+1,w+n+1,greater<int>());
            ans=min(ans,w[k+1]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;++i)vector<int>().swap(e[i]),mx[i]=id[i]=smx[i]=w[i]=fa[i]=0;
    }
    return 0;
}