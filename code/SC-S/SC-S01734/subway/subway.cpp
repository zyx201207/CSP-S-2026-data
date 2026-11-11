#include<bits/stdc++.h>
#define int lld
typedef long long lld;
using namespace std;
inline int min(int a,int b){
    return a<b?a:b;
}
int c,n,m,d,q,w[500005],k,a,t,cnt[500005],dis[505][505],x,y,ans;
struct S{
    int x,t;
};
S e[500005][21];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%lld",w+i);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        for(int j=1;j<=k;j++)
            scanf("%lld%lld",&a,&t),
            e[a][++cnt[a]]={i,t};
    }
    memset(dis,63,sizeof(dis));
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=cnt[i];j++)
            for(int k=j+1;k<=cnt[i];k++){
                S ej=e[i][j],ek=e[i][k];
                dis[ej.x][ek.x]=min(dis[ej.x][ek.x],ej.t+ek.t);
                dis[ek.x][ej.x]=min(dis[ek.x][ej.x],ej.t+ek.t);
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        scanf("%lld%lld",&x,&y);
        ans=1e18;
        for(int i=1;i<=cnt[x];i++)
            for(int j=1;j<=cnt[y];j++)
                ans=min(ans,e[x][i].t+dis[e[x][i].x][e[y][j].x]+e[y][j].t);
        printf("%lld\n",ans+w[x]+w[y]);
    }
}