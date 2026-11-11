#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=505,INF=1e18;
struct edge{
    int v,w;
};
int c,n,m,d,q,a[N],f[M][M],ans;
vector<edge>e[N],g[M];
int read(){
    int k=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
        k=k*10+ch-'0',ch=getchar();
    return k*f;
}
void add(int u,int v,int w){
    f[u][v]=min(f[u][v],w);
    f[v][u]=min(f[v][u],w);
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int k,x,y;
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
        a[i]=read();
    for(int i=1;i<=n;i++){
        k=read();
        for(int j=1;j<=k;j++){
            x=read(),y=read();
            g[i].push_back((edge){x,y});
            e[x].push_back((edge){i,y});
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                f[i][j]=INF;
    for(int i=1;i<=n;i++){
        for(edge j:g[i])
            for(edge p:e[j.v])
                add(i,p.v,p.w+j.w);
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    for(int i=1;i<=q;i++){
        x=read(),y=read();
        ans=INF;
        for(edge j:e[x])
            for(edge k:e[y])
                ans=min(ans,j.w+k.w+f[j.v][k.v]);
        ans+=a[x]+a[y];
        printf("%lld\n",ans);
    }
    return 0;
}