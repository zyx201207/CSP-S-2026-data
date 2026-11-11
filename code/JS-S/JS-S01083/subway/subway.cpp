#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,f[509],k,cnt=0,fa[1000509],cnt1=0,anc[1000509][23],dep[1000509],dis[1000509];
vector<pair<int,int>>g[1000509];
struct node{
    int u,v,w;
}e[500509];
bool cmp(node a,node b){
    return a.w<b.w;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}void merge(int x,int y){
    fa[y]=x;
}void dfs(int u,int ff){
    dep[u]=dep[ff]+1;
    for(auto tmp:g[u]){
        int v=tmp.first,w=tmp.second;
        if(v==ff) continue;
        anc[v][0]=u;
        dis[v]=dis[u]+w;
        dfs(v,u);
    }
}void init(){
    for(int j=1;j<=21;j++){
        for(int i=1;i<=n+m;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int j=21;j>=0;j--){
        if(dep[anc[x][j]]>=dep[y]){
            x=anc[x][j];
        }
    }
    if (x==y) return x;
    for(int j=21;j>=0;j--){
        if(dep[anc[x][j]]!=dep[anc[y][j]]){
            x=anc[x][j];
            y=anc[y][j];
        }
    }
    return anc[x][0];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&f[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            int a,t;
            scanf("%lld%lld",&a,&t);
            e[++cnt]={i+m,a,t};
        }
    }for(int i=1;i<=n+m;i++){
        fa[i]=i;
    }
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx!=fy){
            g[e[i].u].push_back(make_pair(e[i].v,e[i].w));
            g[e[i].v].push_back(make_pair(e[i].u,e[i].w));
            fa[fy]=fx;
            cnt1++;
        }if(cnt1==n+m-1) break;
    }
    dep[1]=1;
    dfs(1,0);
    anc[1][0]=1;
    init();
    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",dis[a]+dis[b]-2*dis[lca(a,b)]+f[a]+f[b]);
    }return 0;
}
