#include<bits/stdc++.h>
using namespace std;

#define Fre(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);

typedef long long ll;

const int N=510,M=5e5+10;

int c,n,m,d,q;
int a[M];
struct Edge{
    int u,w;
};
vector<Edge> trn[N];
vector<Edge> shp[M];
ll G[N][N];

int read(){
    int x=0;
    char c=getchar_unlocked();
    while(c<'0'||c>'9') c=getchar_unlocked();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar_unlocked();
    return x;
}
int main(){
    Fre("subway");

    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;++i) a[i]=read();
    for(int i=1,k,u,w;i<=n;++i){
        k=read();
        while(k--){
            u=read(),w=read();
            trn[i].emplace_back(Edge{u,w});
            shp[u].emplace_back(Edge{i,w});
        }
    }
    memset(G,0x3f,sizeof G);
    for(int i=1;i<=n;++i) G[i][i]=0;
    for(int i=1;i<=n;++i)
        for(auto [u,w]:trn[i])
            for(auto [j,v]:shp[u])
                G[i][j]=min(G[i][j],(ll)w+v);
    // for(int i=1;i<=n;++i,puts(""))
    //     for(int j=1;j<=n;++j)
    //         printf("%lld ",G[i][j]);
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    while(q--){
        int x=read(),y=read();
        ll res=1e18;
        for(auto [i,v]:shp[x])
            for(auto [j,w]:shp[y])
                res=min(res,G[i][j]+v+w);//,printf("%d %d %lld\n",i,j,G[i][j]+v+w);
        printf("%lld\n",res+a[x]+a[y]);
    }

    return 0;
}